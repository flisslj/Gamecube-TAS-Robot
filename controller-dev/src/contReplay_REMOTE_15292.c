#include "contReplay.h"

/**
* contReplay.c
* Robert Gelhar, Senior Design MSOE
* 11/29/2018
* 
* The operation of the controller component is theoretically simple
* Since we're working without the wiringPi SPI, we're using a custom protocol.
* We have four control pins - CLK, RST, SND, RSND
*
* When a frame is requested via the SND pin, we send bytes and wait on the SND signal
* If RSND is sent, we resend starting from the last frame we sent
*/

uint8_t* cmd;
uint8_t* baseCmd;
int REP_BUFFER;

//the reading buffer for the component
//literally just two best friend bytes
//it's because we can only read 8 bits at a time from the mcp
char* readBuffer;

/**
* Initialize the replay component part of the code
*
* In particular, the wiringpi, SPI, cmd, and pins need setup
*/
void replayInit(){
	//initialize the SPI
	//REP_BUFFER = wiringPiSPISetup(MCP_CHANNEL, MCP_SPI_SPEED);
	printf("The file desc is %d\n", REP_BUFFER);
	baseCmd = malloc(sizeof(uint8_t)* 3);
	cmd = malloc(sizeof(uint8_t)* 3);
	readBuffer = malloc(sizeof(char)*2);
	//setup the command
	*(baseCmd + CMD_DEVICE_ADDRESS) = MCP_OPCODE |  (MCP_ADDRESS << 1);
	*(baseCmd + CMD_REGISTER_ADDRESS) = MCP_GPIO_A;
	
	//set up the pins modes
	pinMode(REPLAY_SND, INPUT);
	pinMode(REPLAY_RSND, INPUT);
	pinMode(REPLAY_CLK, OUTPUT);
	pinMode(REPLAY_RST, OUTPUT);
	
	//set up the pulls as well
	pullUpDnControl(REPLAY_RST, PUD_UP);
	pullUpDnControl(REPLAY_CLK, PUD_UP);
	digitalWrite(REPLAY_RST, 1);
	digitalWrite(REPLAY_CLK,1);
	
}

/**
* Reset the component and grab the device information
* The reset protocol is as follows
*
* We hold the component to reset, and then lift the reset signal
* We then wait until the component is ready to transmit half the info
* It signals as such by pulling send down, where we grab the data and ACK via a CLK pulse
* We repeat on the rising edge of the send line and return the data at last
*/
uint16_t replayReset(){
	//so, to do this properly, we reset the component, and then grab the data it gives us
	//we need the chip to act as a temporary input to get the data, and then flip once done
	*(baseCmd + CMD_REGISTER_ADDRESS) = MCP_IODIR_A;
	*(baseCmd + CMD_REGISTER_DATA) = 0xFF; //turn it all on, for inputs
	memcpy(cmd,baseCmd,3);
	wiringPiSPIDataRW(MCP_CHANNEL,cmd,CMD_LENGTH);
	uint16_t info = 0;
	*(baseCmd + CMD_DEVICE_ADDRESS) = MCP_OPCODE |  (MCP_ADDRESS << 1) | 1;
	*(baseCmd + CMD_REGISTER_ADDRESS) = MCP_GPIO_A;
	
	//reset the device
	digitalWrite(REPLAY_RST,0);
	delay(50); //delay 5 ms because why not
	digitalWrite(REPLAY_RST,1);

	//wait until send is low and read the mcp
	while(digitalRead(REPLAY_SND)!=0);
	memcpy(cmd,baseCmd,3);
	wiringPiSPIDataRW(MCP_CHANNEL,cmd,CMD_LENGTH);
	//wiringPiSPIDataRW(MCP_CHANNEL,cmd+2,1);
	*(readBuffer) = *(cmd+2);
	digitalWrite(REPLAY_CLK,0);
	delayMicroseconds(5); //delay 5 us because why not
	digitalWrite(REPLAY_CLK,1);

	//wait until send is high again and read the mcp
	while(digitalRead(REPLAY_SND));
	memcpy(cmd,baseCmd,3);
	wiringPiSPIDataRW(MCP_CHANNEL,cmd,CMD_LENGTH);
	//wiringPiSPIDataRW(MCP_CHANNEL,cmd+2,1);
	*(readBuffer+1) = *(cmd+2);
	digitalWrite(REPLAY_CLK,0);
	delayMicroseconds(50); //delay 50 us because why not
	digitalWrite(REPLAY_CLK,1);
	
	//reset the mcp
	*(cmd + CMD_DEVICE_ADDRESS) = MCP_OPCODE |  (MCP_ADDRESS << 1);
	*(cmd + CMD_REGISTER_ADDRESS) = MCP_IODIR_A;
	*(cmd + CMD_REGISTER_DATA) = 0x00; //turn it all off, for outputs
	wiringPiSPIDataRW(MCP_CHANNEL,cmd,CMD_LENGTH);
	
	//reset the command
	*(baseCmd + CMD_REGISTER_ADDRESS) = MCP_GPIO_A;
	//printf("%d,%d", *(readBuffer), *(readBuffer+1));
	info = *(readBuffer);
	info <<= 8;
	info += *(readBuffer+1);
	
	return info;
}

/**
* Runs the replay device until interrupted
* TODO STOP HAVING ANXIETY I GUESS
*/

void replayRun(){
	return;
}

/** 
* Transmits a byte array of defined length to the replay device
* 
* length - Length of array, in bytes
* data - Pointer to array of data
*
* Returns an enum detailing the success or failure of the transmission
* If the resend signal is never received, the transmission is a success
* If the resend signal is sent at the very end of a transmission, we resend our current frame (CRC failure)
* If the resend signal is sent mid-frame, we send the previous frame (delayed CRC, data noise)
*/
enum frame_state replayTransmit(uint32_t length, uint8_t* data){
	for(int i = 0; i < length; i++){
		if(digitalRead(REPLAY_RSND)==1){
			return RESEND_PREVIOUS;
		}
		replayByte(*(data+i));
		//wait for the next send signal
		while(digitalRead(REPLAY_SND)==1);
	}
	
	//some very short delay to wait for baremetal - less than the time to the next send signal
	
	if(digitalRead(REPLAY_RSND)==1){
		return RESEND_CURRENT;
	}
	
	return SUCCESS;
}


/** 
* Transmits a single byte over SPI to the chip on GPIO A
* 
* byte - the single byte to be sent to the MCP chip
*
*/
void replayByte(uint8_t byte){
	//this is honestly super simple
	*(cmd + CMD_REGISTER_DATA) = byte; //cmd is set up
	wiringPiSPIDataRW(MCP_CHANNEL,cmd,CMD_LENGTH);
	//after this flip the clock down
	digitalWrite(REPLAY_CLK, 0);
	//wait the standard amount (except not really, interrupts eventually)
	delayMicroseconds(CMD_CLK_DELAY_US);
	//flip clock again
	digitalWrite(REPLAY_CLK, 1);
	//wait again lmfao
	delayMicroseconds(CMD_CLK_DELAY_US);
	
	return;
}

