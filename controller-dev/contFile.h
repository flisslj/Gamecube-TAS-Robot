#ifndef CONTROLLER_FILE_H
#define CONTROLLER_FILE_H
//This is a test
char* getFiles(char* basePath);

char* getISOS(char* basePath);

char* getTASes(char* basePath);

uint64_t loadTAS(char* filename, uint8_t[] data);

#endif