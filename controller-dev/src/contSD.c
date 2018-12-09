#include "contSD.h"

static uint8_t* sdCmd= malloc(sizeof(uint8_t)*2);

void SDinit(){
	//set up the second channel
	wiringPiSPISetup(SD_CHANNEL, SD_SPI_SPEED);
	
	pinMode(SD_SND, INPUT);
	pinMode(SD_RSND, INPUT);
}

uint32_t getSDinfo(){
	SDsendCMD(SD_GET_INFO);
	//TODO figure out how the SD interface will let me know it's ready
	uint32_t ret = SDsendCMD(SD_NULL)<<16;
	//TODO figure out how the SD interface will let me know it's ready
	ret += SDsendCMD(SD_NULL);
	return ret;
}

uint64_t getSDsize(){
	SDsendCMD(SD_GET_SIZE);
	//TODO figure out how the SD interface will let me know it's ready
	uint32_t ret = SDsendCMD(SD_NULL)<<48;
	//TODO figure out how the SD interface will let me know it's ready
	ret += SDsendCMD(SD_NULL)<<32;
	//TODO figure out how the SD interface will let me know it's ready
	ret += SDsendCMD(SD_NULL)<<16;
	//TODO figure out how the SD interface will let me know it's ready
	ret += SDsendCMD(SD_NULL);
	
	return ret;
}

uint64_t getSDEmptySpace(){
	SDsendCMD(SD_GET_OPEN_SPACE);
	//TODO figure out how the SD interface will let me know it's ready
	uint32_t ret = SDsendCMD(SD_NULL)<<48;
	//TODO figure out how the SD interface will let me know it's ready
	ret += SDsendCMD(SD_NULL)<<32;
	//TODO figure out how the SD interface will let me know it's ready
	ret += SDsendCMD(SD_NULL)<<16;
	//TODO figure out how the SD interface will let me know it's ready
	ret += SDsendCMD(SD_NULL);
	
	return ret;
}

uint64_t loadISO(char* filename){
	//TODO AAAAAAAAAAA
}

void SDtransmit(uint32_t length, uint8_t* data){
	//TODO ALSO AAAAAAAAAAA
}

uint16_t SDsendCMD(uint16_t cmd){
	
	*(sdCmd) = cmd>>8;
	*(sdCmd+1) = cmd%(1<<8);
	return wiringPiSPIDataRW(SD_SPI_CHANNEL,sdCmd,2);
}