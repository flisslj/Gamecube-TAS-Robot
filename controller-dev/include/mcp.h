#ifndef MCP23S17_H
#define MCP23S17_H

#include <stdint.h>

#define SPI_SPEED 10000000 //10 MHZ

#define MCP_CHANNEL 1

#define MCP_OPCODE 0x40
#define MCP_ADDRESS 7
#define MCP_IODIR_A 0x0
#define MCP_IODIR_B 0x1
#define MCP_GPIO_A 0x12
#define MCP_GPIO_B 0x13

#define CMD_DEVICE_ADDRESS 0
#define CMD_REGISTER_ADDRESS 1
#define CMD_REGISTER_DATA 2
#define CMD_LENGTH 3

#endif