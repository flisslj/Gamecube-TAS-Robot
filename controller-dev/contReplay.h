#ifndef CONTROLLER_REPLAY_INTERFACE_H
#define CONTROLLER_REPLAY_INTERFACE_H

#include <stdint.h>
#include <wiringPi.h>

#define OPCODE 0x40
#define SPI_SPEED 10000000 //10 MHZ
#define REPLAY_CHANNEL 1

#define MCP_ADDRESS 7
#define MCP_IODIR_A 0x0
#define MCP_IODIR_B 0x1
#define MCP_GPIO_A 0x12
#define MCP_GPIO_B 0x13

#define CMD_DEVICE_ADDRESS 0
#define CMD_REGISTER_ADDRESS 1
#define CMD_REGISTER_DATA 2
#define CMD_LENGTH 3
#define CMD_CLK_DELAY_US 10

#define REPLAY_SND
#define REPLAY_RSND
#define REPLAY_RST
#define REPLAY_CLK

#define INFO_REQUEST_CMD

enum frame_state{SUCCESS, RESEND_CURRENT, RESEND_PREVIOUS}

uint16_t replayReset();

void replayInit();

enum frame_state replayTransmit(uint32_t length, uint8_t* data);

void replayByte(uint8_t byte);

#endif