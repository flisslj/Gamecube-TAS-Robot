#include "cont.h"

char* currentISO;
char* currentTAS;

void contInit(void){
	wiringPiSetupPhys();
	memInit();
	replayInit();
	SDinit();
	currentISO = malloc(sizeof(char) * MAX_FILENAME_LENGTH);
	currentTAS = malloc(sizeof(char) * MAX_FILENAME_LENGTH);
	return;
}

uint64_t getAttachedHardware(){
	uint64_t contInfo = CONTROLLER_TYPE<<8 | CONTROLLER_VERSION;
	uint64_t replayInfo = replayReset();
	uint64_t SDinfo=0x02010000; //getSDinfo();
	//SD is 32 bits, the others are 16.
	uint64_t returnValue = (contInfo<<48) + (replayInfo<<32) + (SDinfo<<0);
	return returnValue;
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
	return true;
}

bool setTas(char* tasPath){
	//find out whether we have the tas path
	//???//
	//if so, we can cut off the filename
	strcpy(currentTAS, basename(tasPath));
	return true;
}

//TODO
bool contRun(){
	
	return false;
}

//TODO
bool contAbort(){
	
	return false;
}
