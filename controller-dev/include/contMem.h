/**
* contMem.h
* Robert Gelhar, Senior Design MSOE
* 12/2/2018
* 
* Header for the controller memory handler
* Mostly incomplete
*/

#ifndef CONTROLLER_MEMDUMP_INTERFACE_H
#define CONTROLLER_MEMDUMP_INTERFACE_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <wiringPi.h>		//for SPI interraction, pin setting and reading
#include <wiringPiSPI.h>	//especially for SPI
#include "mcp.h"

void memInit();

char* getMemoryDump();

uint64_t getMemoryDumpData();

bool clearMemoryDump();

#endif