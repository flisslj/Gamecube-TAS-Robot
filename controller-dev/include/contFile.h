#ifndef CONTROLLER_FILE_H
#define CONTROLLER_FILE_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h> 
#include <dirent.h>
#include <stdbool.h> 

char* getFiles(char* basePath);

char* getISOs(char* basePath);

char* getTASes(char* basePath);

uint64_t loadTAS(char* filename);

bool setTAS(char* filename);

#endif