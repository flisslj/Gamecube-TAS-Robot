#ifndef CONTROLLER_REPLAY_INTERFACE_H
#define CONTROLLER_REPLAY_INTERFACE_H

#include <stdint.h>
#include <wiringPi.h>
#include "mcp.h"

#define CMD_CLK_DELAY_US 10

//TODO
#define REPLAY_SND
#define REPLAY_RSND
#define REPLAY_RST
#define REPLAY_CLK

enum frame_state{SUCCESS, RESEND_CURRENT, RESEND_PREVIOUS}

uint16_t replayReset();

void replayInit();

enum frame_state replayTransmit(uint32_t length, uint8_t* data);

void replayByte(uint8_t byte);

#endif