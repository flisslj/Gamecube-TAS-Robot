#ifndef CONTROLLER_SD_INTERFACE_H
#define CONTROLLER_SD_INTERFACE_H

#include <stdint.h>
#include <string.h>

uint32_t getSDinfo();

uint64_t getSDsize();

uint64_t getSDEmptySpace();

char* getSDFiles();

char* getSDISOS();

char* getSDTASes();

uint64_t loadISO(char* filename, uint8_t[] data);

uint64_t loadTAS(char* filename, uint8_t[] data);


void SDtransmit(uint32_t length, uint8_t* data);

void SDsendCMD(uint8_t cmd);

#endif