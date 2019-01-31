/**
* mcp.h
* Robert Gelhar, Senior Design MSOE
* 12/2/2018
* 
* Header for the MCP SPI chip
* This is used both in the replay device and the memory device
*/

#ifndef MCP23S17_H
#define MCP23S17_H

#include <stdint.h>

#define MCP_SPI_SPEED 	10000000 //10 MHZ

#define MCP_CHANNEL 	1 //channel 0 is reserved for SD interface

#define MCP_OPCODE 		0x40 //opcode for the first nibble of a command
#define MCP_ADDRESS 	0x7  //address pins should all be 1
#define MCP_IODIR_A 	0x0  //determines io direction for GPIOA
#define MCP_IODIR_B 	0x1	 //determines io direction for GPIOB
#define MCP_GPIO_A 		0x12 //direct pinout GPIOA
#define MCP_GPIO_B 		0x13 //direct pinout GPIOB

//this lays out a command format for the MCP device
//the first byte is an opcode and a device address
//the second indicates an address and a read or write command
//the third either pushes out the data from a read
//or is the data to write

#define CMD_DEVICE_ADDRESS 		0
#define CMD_REGISTER_ADDRESS 	1
#define CMD_REGISTER_DATA 		2
#define CMD_LENGTH 				3

#endif