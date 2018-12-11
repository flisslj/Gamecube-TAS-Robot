/**
* contReplay.h
* Robert Gelhar, Senior Design MSOE
* 12/1/2018
* 
* Header for the controller input device interraction
* 
*/

#ifndef CONTROLLER_REPLAY_INTERFACE_H
#define CONTROLLER_REPLAY_INTERFACE_H

#include <stdint.h>			//for standard int types on devices
#include <wiringPi.h>		//for SPI interraction, pin setting and reading
#include <wiringPiSPI.h>	//especially for SPI
#include "mcp.h"			//for various mcp23s17 information

#define CMD_CLK_DELAY_US 10 //arbitrary value, to be measured and changed

//TODO
#define REPLAY_SND 		29 // the send line for replay
#define REPLAY_RSND 	31 // the resend line for replay
#define REPLAY_RST 		22 // the reset line (in general)
#define REPLAY_CLK 		32 // the clock line for transmissions

enum frame_state{SUCCESS, RESEND_CURRENT, RESEND_PREVIOUS}

uint16_t replayReset();

void replayRun();

void replayInit();

enum frame_state replayTransmit(uint32_t length, uint8_t* data);

void replayByte(uint8_t byte);

#endif