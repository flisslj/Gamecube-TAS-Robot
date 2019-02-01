#include "cont.h"

char* currentISO;
char* currentTAS;

char* tasBytes;
char* tasBytesOffset;

boolean isRunInit;

void contInit(void){
	wiringPiSetupPhys();
	memInit();
	replayInit();
	SDinit();
	currentISO = malloc(sizeof(char) * MAX_FILENAME_LENGTH);
	currentTAS = malloc(sizeof(char) * MAX_FILENAME_LENGTH);
	//we haven't initialzed the running yet
	isRunInit = false;
	return;
}

uint64_t getAttachedHardware(){
	uint64_t contInfo = CONTROLLER_TYPE<<8 | CONTROLLER_VERSION;
	uint64_t replayInfo = replayReset();
	uint64_t SDinfo=0x02010000; 
	getSDinfo();
	//SD is 32 bits, the others are 16.
	uint64_t returnValue = (contInfo<<48) + (replayInfo<<32) + (SDinfo<<0);
	return returnValue;
}

char* getCurrentISO(){
	return basename(currentISO);
}

char* getCurrentTAS(){
	return basename(currentTAS);
}

bool setISO(char* isoPath){
	//find out whether the SD component has the iso path
	if(access(isoPath, F_OK) == -1){return false;}
	//if so, we can cut off the filename
	strcpy(currentTAS, isoPath);
	return true;
}

bool setTas(char* tasPath){
	//find out whether we have the tas path
	if(access(tasPath, F_OK) == -1){return false;}
	//if so, we can cut off the filename
	strcpy(currentTAS, tasPath);
	return true;
}

/*
* This function, in particular, will basically do one thing - attend to the needs of replay
* in theory we can also do a little bit with SD but otherwise not really
* Since this is a "polling" function, we treat every run seperately
*/
bool contRun(){
	if(!isRunInit){
		//to initialiZe the run, we have to load up the current TAS into charspace
		//assume it's basepath and run
		FILE* tasFile;
		tasFile = fopen(tasPath);
		//first, we need the size for allocation
		fseek(tasFile, 0L, SEEK_END);
		int size = ftell(tasFile);
		rewind(tasFile);
		tasBytes = malloc(sizeof(char)*size);
		int h = fread(tasBytes,1,size,tasFile);
		if(h==-1 || h ==0){
			free(tasBytes);
			fclose(tasFile);
			return false;
		}
		isRunInit = true;
	}
	
	//now we check to see if the replay device wants a set of 40
	if(digitalRead(REPLAY_SND)==0){
		//we'll send a set of 40 bytes
		enum frame_state currentState = replayTransmit(40,(tasBytes+tasbytesOffset));
		while(currentState !=SUCCESS){
			while(digitalRead(REPLAY_SND)==1);
			if(currentState == REPLAY_PREVIOUS){
				if(tasBytesOffset==0){
					currentState = replayTransmit(40,(tasBytes+tasbytesOffset));
				}else{
					currentState = replayTransmit(40,(tasBytes+tasbytesOffset-40));
				}
			}else{
				currentState = replayTransmit(40,(tasBytes+tasbytesOffset));
			}
		}
	}
	
	return true;
}

//TODO
bool contAbort(){
	
	return false;
}
