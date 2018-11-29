#include "cont.h"

static char* currentISO = malloc(sizeof(char) * MAX_FILENAME_LENGTH);
static char* currentTAS = malloc(sizeof(char) * MAX_FILENAME_LENGTH);

bool heartbeat(){
	return true; //wait lmao
}

uint64_t getAttachedHardware(){
	uint64_t contInfo = CONTROLLER_TYPE<<8 | CONTROLLER_VERSION;
	uint64_t replayInfo = getReplayInfo();
	uint64_t SDinfo = getSDinfo();
	
	//SD is 32 bits, the others are 16.
	return (contInfo<<48) | (replayInfo)<<32) | (SDinfo<<0);
}

char* getCurrentISO(){
	return currentISO;
}

char* getCurrentTAS(){
	return currentTAS;
}

bool setISO(char* isoPath){
	//find out whether the SD component has the iso path
	//???//
	//if so, we can cut off the filename
	strcpy(currentTAS, basename(isoPath));
}

bool setTas(char* tasPath){
	//find out whether the SD component has the tas path
	//???//
	//if so, we can cut off the filename
	strcpy(currentTAS, basename(tasPath));
}

//TODO
bool run(){
	
	return false;
}

//TODO
bool abort(){
	
	return false;
}