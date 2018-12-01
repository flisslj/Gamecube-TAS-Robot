#ifndef CONTROLLER_REPLAY_INTERFACE_H
#define CONTROLLER_REPLAY_INTERFACE_H

#include <stdint.h>
#include <wiringPi.h>
#include "mcp.h"

#define CMD_CLK_DELAY_US 10

//TODO
#define REPLAY_SND 29
#define REPLAY_RSND 31
#define REPLAY_RST 25
#define REPLAY_CLK 33

enum frame_state{SUCCESS, RESEND_CURRENT, RESEND_PREVIOUS}

uint16_t replayReset();

void replayInit();

enum frame_state replayTransmit(uint32_t length, uint8_t* data);

void replayByte(uint8_t byte);

#endif