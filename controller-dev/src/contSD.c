#include "contSD.h"

static uint8_t* sdCmd= malloc(sizeof(uint8_t)*2);

/**
* Initializes the SD function
*
* All it really needs to do is set up SND, RSND, and the SPI channel
*/
void SDinit(){
	//set up the second channel
	wiringPiSPISetup(SD_CHANNEL, SD_SPI_SPEED);
	
	pinMode(SD_SND, INPUT);
	pinMode(SD_RSND, INPUT);
}

/**
* Acquires the SD info
*
* Sends the command for getting info, and then full duplexes for 32 bits into buffer
*/

//TODO - check if the sd function returns a filedescriptor or data
uint32_t getSDinfo(){
	
	SDsendCMD(SD_GET_INFO);
	//wait for snd to go low
	while(digitalRead(SD_SND)==1);
	uint32_t ret = SDsendCMD(SD_NULL)<<16;
	//now we wait for a snd to go back high
	while(digitalRead(SD_SND)==0);
	ret += SDsendCMD(SD_NULL);
	return ret;
}

uint64_t getSDsize(){
	SDsendCMD(SD_GET_SIZE);
	while(digitalRead(SD_SND)==1);
	
	uint32_t ret = SDsendCMD(SD_NULL)<<48;
	while(digitalRead(SD_SND)==1);
	ret += SDsendCMD(SD_NULL)<<32;
	while(digitalRead(SD_SND)==1);
	ret += SDsendCMD(SD_NULL)<<16;
	while(digitalRead(SD_SND)==1);
	ret += SDsendCMD(SD_NULL);
	while(digitalRead(SD_SND)==1);
	
	return ret;
}

uint64_t getSDEmptySpace(){
	SDsendCMD(SD_GET_OPEN_SPACE);
	while(digitalRead(SD_SND)==1);
	
	uint32_t ret = SDsendCMD(SD_NULL)<<48;
	while(digitalRead(SD_SND)==1);
	ret += SDsendCMD(SD_NULL)<<32;
	while(digitalRead(SD_SND)==1);
	ret += SDsendCMD(SD_NULL)<<16;
	while(digitalRead(SD_SND)==1);
	ret += SDsendCMD(SD_NULL);
	while(digitalRead(SD_SND)==1);
	
	return ret;
}

/**
*/
uint64_t loadISO(char* filename){
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
	char* buffer = malloc(sizeof(char)*SD_FRAME_SIZE);
	
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
	}
	
	//and now we've transmit everything
	//that wasn't that bad, i suppose
	free(buffer);
	fclose(iso);
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
	//first, transmit the data directly over the channel
	wiringPiSPIDataRW(SD_SPI_CHANNEL,data,length);
	//next, calculate the CRC and send it over
	//TODO
	
}

uint16_t SDsendCMD(uint16_t cmd){
	
	*(sdCmd) = cmd>>8;
	*(sdCmd+1) = cmd%(1<<8);
	return wiringPiSPIDataRW(SD_SPI_CHANNEL,sdCmd,2);
}