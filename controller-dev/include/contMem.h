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