#ifndef CONTROLLER_SD_INTERFACE_H
#define CONTROLLER_SD_INTERFACE_H

#include <stdint.h>
#include <string.h>

uint32_t getSDinfo();

uint64_t getSDsize();

uint64_t getSDEmptySpace();

uint64_t loadISO(char* filename);

void SDtransmit(uint32_t length, uint8_t* data);

void SDsendCMD(uint8_t cmd);

#endif