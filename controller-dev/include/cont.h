/**
* cont.h
* Robert Gelhar, Senior Design MSOE
* 11/29/2018
* 
* Header for the controller file, which does the actual functions as prescribed by main
* These are laid out in the Main Controller API doc on drive
*/

#ifndef CONTROLLER_INTERFACE_H
#define CONTROLLER_INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <wiringPi.h>
#include <libgen.h>

#include "contSD.h"
#include "contMem.h"
#include "contReplay.h"
#include "contFile.h"

#define CONTROLLER_TYPE 		0 //arbitrary value, we'll call RasPi as "0"
#define CONTROLLER_VERSION 		1 //arbitrary value, standard version is 1

#define HEARTBEAT_CONFIRM 		0xDEADDEEF //agreed upon value

#define MAX_FILENAME_LENGTH 	512 //arbitrary, can be expanded


uint64_t getAttachedHardware();

char* getCurrentISO();

char* getCurrentTAS();

bool setISO(char* isoPath);

bool setTas(char* tasPath);

bool loadTas(char* tasPath);

bool run();

bool abort();

#endif