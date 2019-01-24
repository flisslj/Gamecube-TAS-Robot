/**
* contSD.h
* Robert Gelhar, Senior Design MSOE
* 12/2/2018
* 
* Header for the controller SD interface
*/

#ifndef CONTROLLER_SD_INTERFACE_H
#define CONTROLLER_SD_INTERFACE_H

//(8,4)Hamming X 2 encoded
//In theory, this allows for, at a minimum, a correction of 2 bit errors, detection up to 4
//A single (8,4) allows to correction of 1, detection of 2

/*If two errors happen on one side, you can compare to the uncorrupted one 
and determine the uncorrupted to be valid */
/*If three errors happen on one side, one on another, a double corruption 
correcting to different values can be tossed */
/*If four errors happen on one side, a single-error correction not lining 
up with the expected uncorrupted can be tossed */

//I'm proud of how stupid this is
//also, this allows for up to 16 total commands - more than enough

#define SD_NULL 		0x0000
#define SD_GET_INFO 		0x1B1B
#define SD_GET_SIZE 		0x2D2D
#define SD_GET_OPEN_SPACE 	0x3636
#define SD_LOAD_ISO 		0x4E4E

#define SD_SPI_SPEED 		10000000 //10 MHZ
#define SD_SPI_CHANNEL 			0 //reserved for the SD, 1 is for the mcp chip
#define SD_FRAME_SIZE		128

#define SD_SND				16 		//pin number for send pin
#define SD_RSND				18		//pin number for resend pin
#define SD_CMD				15		//pin number for indicator

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>			//for standard int types
#include <stdio.h>			//for file reading
#include <string.h>			//for string returns for file names (possibly irrelevant?)
#include <stdbool.h>		//loadiso returns true on success, false on failure
#include <wiringPi.h>		//for pin interraction, SPI
#include <wiringPiSPI.h> 	//especially for SPI
#include <sys/stat.h>		//for file sizing
#include "mcp.h"			//for various SPI information in general (irrelevant?)

void SDinit();

uint32_t getSDinfo();
uint64_t getSDsize();
uint64_t getSDEmptySpace();

bool loadISO(char* filename);

void SDtransmit(uint32_t length, uint8_t* data);
uint16_t SDsendCMD(uint16_t cmd);

#endif