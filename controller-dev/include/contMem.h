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

#include <stdint.h>
#include <stdbool.h>
#include "mcp.h"

void memInit();

char* getMemoryDump();

char* getMemoryDumpData();

bool clearMemoryDump();

#endif