#include "contSD.h"

//the command to send to the sd card
//the onboard spi component only takes chars
//even though we send 16 bits at a time, we need two bytes
//honestly you could shoot me in the knee and i wouldn't even feel it
char* sdCmd;

//file descriptor for the spi buffer
int SD_SPI_BUFFER;

//the reading buffer for the component
//the largest number the SD card returns is a 64 bit int
//we get it in 16 bit chunks, so 4*16 = 64
uint16_t* readBuffer;

/**
* Initializes the SD function
*
* All it really needs to do is set up SND, RSND, and the SPI channel
*/
void SDinit(){
	//set up the second channel
	SD_SPI_BUFFER = wiringPiSPISetup(SD_SPI_CHANNEL, SD_SPI_SPEED);
	
	sdCmd= malloc(sizeof(char)*2);
	readBuffer = malloc(sizeof(uint16_t)*4);

	//both snd and rsnd are controlled by the board
	//we pull up anyway, for posterity
	pinMode(SD_SND, INPUT);
	pinMode(SD_RSND, INPUT);
	pullUpDnControl(SD_SND, PUD_UP);
	pullUpDnControl(SD_RSND, PUD_UP);
}

/**
* Acquires the SD info
*
* Sends the command for getting info, and then full duplexes for 32 bits into buffer
* The assumed format goes as so:
* [31:24] - SD Component type (1 for raspberry pi, 2 for stm32, 3 for ???)
* [23:16] - SD Component version
* [15:0] - SD card capacity, in mB (0 indicates no card connection)
*/
uint32_t getSDinfo(){
	//Here's the general process in order to grab stuff from the spi
	//This is used for most of the commands here
	
	//Send the command magic number to the SPI
	SDsendCMD(SD_GET_INFO);
	for(int i = 0; i < sizeof(uint32_t)/sizeof(uint16_t); i++){
		//Wait for an indication 
		while(digitalRead(SD_SND)==1);
		//Send an empty command to retrieve the data
		//This also interrupts the SD component to get the next 16 bits
		SDsendCMD(SD_NULL);
		//Read the data from the SPI buffer
		read(SD_SPI_BUFFER,readBuffer+i,1);
	}
	
	//now that we have the data, we just convert it to uint32_t
	//this assumes big endian
	return (((uint32_t)(*readBuffer))<<16 + *(readBuffer+1));
}

/**
* Acquires the SD card size
*
* Returns the size, in 512 byte blocks (0 means a disconnected card)
* Note that the maximum size is 9.22 zettabytes, 
* which is twice that of what the entire human race produced up to 2013
*/
uint64_t getSDsize(){
	
	//Send the command magic number to the SPI
	SDsendCMD(SD_GET_SIZE);
	//Wait for an indication
	for(int i = 0; i < sizeof(uint64_t)/sizeof(uint16_t); i++){
		while(digitalRead(SD_SND)==1);
		SDsendCMD(SD_NULL);
		read(SD_SPI_BUFFER,(readBuffer+i),1);
	}
	
	//convert the short array into a long long
	uint64_t returnValue = 0;

	//this value exists due to typecasting
	//it's a pain
	uint64_t tempVal = 0;
	tempVal = *(readBuffer);
	returnValue += tempVal<<48;
	tempVal = *(readBuffer+1);
	returnValue += tempVal<<32;
	tempVal = *(readBuffer+2);
	returnValue += tempVal<<16;
	returnValue += *(readBuffer+3);
	
	return returnValue;
}

/**
* Acquires the SD card empty space
*
* Returns the size, in 512 byte blocks (0 means a disconnected card)
*/
uint64_t getSDEmptySpace(){
	//Send the command magic number to the SPI
	SDsendCMD(SD_GET_OPEN_SPACE);
	//Wait for an indication
	for(int i = 0; i < sizeof(uint64_t)/sizeof(uint16_t); i++){
		while(digitalRead(SD_SND)==1);
		SDsendCMD(SD_NULL);
		read(SD_SPI_BUFFER,(readBuffer+i),1);
	}
	
	//convert the short array into a long long
	uint64_t returnValue = 0;
	//this value exists due to typecasting
	//it's a pain
	uint64_t tempVal = 0;
	tempVal = *(readBuffer);
	returnValue += tempVal<<48;
	tempVal = *(readBuffer+1);
	returnValue += tempVal<<32;
	tempVal = *(readBuffer+2);
	returnValue += tempVal<<16;
	returnValue += *(readBuffer+3);
	
	return returnValue;
}

/**
* Loads an ISO file over SPI
*
* This one is a bit expansive, but the general gist is this-
* - First, it sends the command, waits for ACK, then sends the file size
* - After an ACK from that, it proceeds to send the ISO in 130 byte chunks
* - The first 128 bytes are pure data, while the last two are CRC-16
* - If, at any point, when SND is low, RSND is low, we resend the last block
*/
bool loadISO(char* filename){
	//so, we need to first figure out the length of the iso, in bytes
	struct stat st;
	stat(filename, &st);
	uint32_t size = st.st_size;
	
	//that's a big honkin file
	//well, let's do our best.
	//first, let's let the SD component know it's about to get rocked
	SDsendCMD(SD_LOAD_ISO);
	while(digitalRead(SD_SND)==1);
	
	//k, it knows now
	//man, i'm so sorry, but this has to happen
	//let's give it a clue to how much stuff it has to handle
	SDsendCMD(size>>16);
	while(digitalRead(SD_SND)==1);
	SDsendCMD(size%(1<<16));
	while(digitalRead(SD_SND)==1);
	
	//alright, man, if you think you can handle it, we begin the process
	//first, we open the file up to get at its core
	FILE *iso = fopen(filename, "r");
	
	//we create a byte buffer
	char* buffer = malloc(sizeof(char) * (SD_FRAME_SIZE+2));
	
	for(int i = 0; i < size/SD_FRAME_SIZE; i++){
		//we still have a 128 byte chunk, so send it
		fread(buffer, SD_FRAME_SIZE, 1, iso);
		SDtransmit(SD_FRAME_SIZE, buffer);
		//wait for an ACK
		while(digitalRead(SD_SND)==1);
		
		//make sure it's not NACKing
		while(digitalRead(SD_RSND)==0){
			SDtransmit(SD_FRAME_SIZE, buffer);
			while(digitalRead(SD_SND)==1);
		}
		//assuming the iso progresses automatically, we just continue
	}
	
	//we now have a slight remainder left, in theory
	if((size%SD_FRAME_SIZE)!=0){
		fread(buffer, (size%SD_FRAME_SIZE), 1, iso);
		SDtransmit(size%SD_FRAME_SIZE, buffer);
		
		while(digitalRead(SD_SND)==1);
		//make sure it's not NACKing
		while(digitalRead(SD_RSND)==0){
			SDtransmit(SD_FRAME_SIZE, buffer);
			while(digitalRead(SD_SND)==1);
		}
	}
	
	//and now we've transmit everything
	//that wasn't that bad, i suppose
	free(buffer);
	fclose(iso);
	
	return true;
}

/**
* Transmits a block of data to the SD card
* 128 bytes of data (or less) will be sent, followed by a 16 bit CRCF
*
* First, we transmit the length, then the data chunks, until end
* 
* uint32_t - Length, in bytes
* uint8_t* data - the data to be transmitted
*/
void SDtransmit(uint32_t length, uint8_t* data){
	//first, calculate CRC-16 on the data
	//TODO
	//then, send the entire buffer
	wiringPiSPIDataRW(SD_SPI_CHANNEL,data,length+2);
	return;
}

/**
* Transmits a single 16 byte command over to the SD component
*
* It converts the 16 bit integer to a byte array, then uses the wiringpi library
*/
void SDsendCMD(uint16_t cmd){
	
	*(sdCmd) = cmd>>8;
	*(sdCmd+1) = cmd%(1<<8);
	wiringPiSPIDataRW(SD_SPI_CHANNEL,sdCmd,2);
	return;
}