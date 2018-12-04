/**
* main.h
* Robert Gelhar, Senior Design MSOE
* 12/3/2018
* 
* Header for the main parsing file
* Handles the interaction between stdin/stdout and cont.c
*/

#ifndef MAIN_H
#define MAIN_H

#include "cont.h"
#include "contBase64.h"
#include <stdio.h>
#include <string.h>


#define MAX_STDIN_CMD_LENGTH 	200 //file paths might make this bigger than 200

#define HEARTBEAT_IN 			0xDEADDEEF //GOOD JOKE
#define HEARTBEAT_OUT 			0x21522110 //inverted version of HEARTBEAT_IN

#endif