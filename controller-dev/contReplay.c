#include "contReplay.h"

/**
* contReplay.c
* Robert Gelhar, Senior Design MSOE
* 11/29/2018
* 
* The operation of the controller component is theoretically simple
* Since we're working without SPI, we're using a custom protocol.
* We have four control pins - CLK, RST, TX, RX - and 8 bits of data through SPI.
* The operation is theoretically simple.
* 
* To transmit data to the component, TX is turned on
* Then, every falling edge of the CLK we control, data is the next trasmitted bit
* This will happen in 40 byte chunks.
*
* To receive data, a command is sent and the RX line is watched.
* We act as the slave for, at most, a 16 bit integer (i think)
*/

static uint8_t* cmd = malloc(sizeof(uint8_t)* 3)

//TODO
uint16_t getReplayInfo(){
	
}

void playInit(){
	//initialize the SPI
	int fd0 = wiringPiSPISetup(REPLAY_CHANNEL, SPI_SPEED);
	//setup the command
	*(cmd + CMD_DEVICE_ADDRESS) = OPCODE |  (MCP_ADDRESS << 1);
	*(cmd + CMD_REGISTER_ADDRESS) = MCP_GPIO_A;
	//set up the pins modes
	pinMode(REPLAY_TX, OUTPUT);
	pinMode(REPLAY_RX, INPUT);
	pinMode(REPLAY_CLK, OUTPUT);
	pinMode(REPLAY_RST, OUTPUT);
	//set up the pulls as well
	pullUpDnControl(REPLAY_RST, PUD_UP);
	pullUpDnControl(REPLAY_CLK, PUD_DOWN);
}

//TODO
void playTransmit(uint32_t length, uint8_t* data){
	for(int i = 0; i < length; i++){
		playByte(*(data+i));
	}
	
	return;
}

//TODO
void playByte(uint8_t byte){
	//this is honestly super simple
	*(cmd + CMD_REGISTER_DATA) = byte; //cmd is set up
	wiringPiSPIDataRW(REPLAY_CHANNEL,cmd,CMD_LENGTH);
	//after this flip the clock down
	digitalWrite(REPLAY_CLK, 0);
	//wait the standard amount (except not really, interrupts eventually)
	//TODO
	//flip clock again
	digitalWrite(REPLAY_CLK, 1);
	//wait again lmfao
	//TODO
	
	return;
}