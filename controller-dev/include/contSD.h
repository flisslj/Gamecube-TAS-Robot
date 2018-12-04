/**
* contSD.h
* Robert Gelhar, Senior Design MSOE
* 12/2/2018
* 
* Header for the controller SD interface
* Mostly incomplete
*/

#ifndef CONTROLLER_SD_INTERFACE_H
#define CONTROLLER_SD_INTERFACE_H

//(8,4)Hamming X 2 encoded
#define SD_NULL 			0x0000
#define SD_GET_INFO 		0x1B1B
#define SD_GET_SIZE 		0x2D2D
#define SD_GET_OPEN_SPACE 	0x3636
#define SD_LOAD_ISO 		0x4E4E

#define SD_SPI_SPEED 		10000000 //10 MHZ
#define SD_CHANNEL 			0 //reserved for the SD, 1 is for the mcp chip

#define SD_SND
#define SD_RSND

#include <stdint.h>
#include <string.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include "mcp.h"

void SDinit();

uint32_t getSDinfo();

uint64_t getSDsize();

uint64_t getSDEmptySpace();

uint64_t loadISO(char* filename);

void SDtransmit(uint32_t length, uint8_t* data);

void SDsendCMD(uint16_t cmd);

#endif