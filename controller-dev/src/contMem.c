#include "contMem.h"

static uint8_t* memcmd = malloc(sizeof(uint8_t)* 3)

/**
* Initializes the memory components for operation
*
* In particular, the wiringpi, SPI, and memcmd.
* There may be additional pins for memory dump control purposes
*/
void memInit(){
	//initialize the SPI
	int fd0 = wiringPiSPISetup(MCP_CHANNEL, MCP_SPEED);
	
	//this makes the b gpio input
	*(memcmd+CMD_DEVICE_ADDRESS) = MCP_OPCODE |  (MCP_ADDRESS << 1);
	*(memcmd + CMD_REGISTER_ADDRESS) = MCP_IODIR_B;
	*(memcmd + CMD_REGISTER_DATA) = 0xFF;
	wiringPiSPIDataRW(MCP_CHANNEL,memcmd,CMD_LENGTH);
	
	//setting up the cmd to read at will
	*(memcmd+CMD_DEVICE_ADDRESS) = MCP_OPCODE |  (MCP_ADDRESS << 1) | 1;
	*(memcmd + CMD_REGISTER_ADDRESS) = MCP_GPIO_B;
}