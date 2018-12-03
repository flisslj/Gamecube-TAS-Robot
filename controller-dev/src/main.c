#include "main.h"

/**
* main.c
* Robert Gelhar, Senior Design MSOE
* 11/29/2018
*
* This program is the conduit between multiple actions running on the Raspi controller
* Its main purpose is to interface with about 5 entities
*
* The onboard server to do Ethernet connection with computer
* The computer itself through USART (subject to change)
* The STM32 F7 to trade files and commands back and forth
* The baremetal Raspi to trade commands and send 40 byte interface packets
* The port onboard the gamecube for memory dump retrieval
*/

/**
* running main has some format TBD
*/
int main(int argc, char *argv[]){
	
	char* command = malloc(sizeof(char)*MAX_STDIN_CMD_LENGTH);
	
	//handles grabbing and returns commands through stdin
	while(1){
		//spinlock until we get a command
		//this means functions like run should be interrupt-driven
		//unless we can slap interrupts on this in which case nvm
		while(fgets(command,MAX_STDIN_CMD_LENGTH,stdin)==NULL);
		
		//we now have a command, let's parse it
		if(strcmp(command,"hardware")==0){
			uint64_t ret = getAttachedHardware();
			//encode ret into base 64
			char* returnString = malloc(sizeof(char)*LONG_TO_BASE64_LENGTH);
			longToBase64(ret,returnString);
			//then return it
			fprintf(stdout,returnString);
			//and free memory
			free(returnString);
		}else if(strncmp(command,"heartbeat:",10)==0){
			//we then grab the variable and then determine whether to return error or confirmation
			//TODO
		}else if(strcmp(command,"sdsize")==0){
			uint64_t ret = getSDsize();
			//encode ret into base 64
			char* returnString = malloc(sizeof(char)*LONG_TO_BASE64_LENGTH);
			longToBase64(ret,returnString);
			//then return it
			fprintf(stdout,returnString);
			//and free memory
			free(returnString);
		}else if(strcmp(command,"sdopen")==0){
			uint64_t ret = getSDEmptySpace();
			//encode ret into base 64
			//encode ret into base 64
			char* returnString = malloc(sizeof(char)*LONG_TO_BASE64_LENGTH);
			longToBase64(ret,returnString);
			//then return it
			fprintf(stdout,returnString);
			//and free memory
			free(returnString);
		}else if(strcmp(command,"getfiles")==0){
			fprintf(stdout,getFiles(/*TODO basepath*/));
		}else if(strcmp(command,"getisos")==0){
			fprintf(stdout,getISOs(/*TODO basepath*/));
		}else if(strcmp(command,"gettases")==0){
			fprintf(stdout,getTASes(/*TODO basepath*/));
		}else if(strcmp(command,"getcurrentiso")==0){
			fprintf(stdout,getCurrentISO(/*TODO basepath*/));
		}else if(strcmp(command,"getcurrenttas")==0){
			fprintf(stdout,getCurrentTAS(/*TODO basepath*/));
		}else if(strncmp(command,"settas:",7)==0){
			//move the pointer over 7
			if(setTAS(command + 7)){
				fprintf(stdout, "TRUE");
			}else{
				fprintf(stdout, "FALSE");
			}
		}else if(strcmp(command,"setiso:",7)==0){
			//move the pointer over 7
			if(setISO(command + 7)){
				fprintf(stdout, "TRUE");
			}else{
				fprintf(stdout, "FALSE");
			}
		}else if(strcmp(command,"loadiso:",8)==0){
			//move the pointer over 8
			if(loadISO(command + 8)){
				fprintf(stdout, "TRUE");
			}else{
				fprintf(stdout, "FALSE");
			}
		}else if(strcmp(command,"loadtas:",8)==0){
			//move the pointer over 8
			if(loadTAS(command + 8)){
				fprintf(stdout, "TRUE");
			}else{
				fprintf(stdout, "FALSE");
			}
		}else if(strcmp(command,"run")==0){
			if(run()){
				fprintf(stdout, "TRUE");
			}else{
				fprintf(stdout, "FALSE");
			}
		}else if(strcmp(command,"abort")==0){
			if(run()){
				fprintf(stdout, "TRUE");
			}else{
				fprintf(stdout, "FALSE");
			}
		}else if(strcmp(command,"getmemorydump")==0){
			//TODO 
			//fprintf(stdout, getMemoryDump());
		}else if(strcmp(command,"getmemorydumpdata")==0){
			uint64_t ret = getMemoryDumpData();
			//encode ret into base 64
			char* returnString = malloc(sizeof(char)*LONG_TO_BASE64_LENGTH);
			longToBase64(ret,returnString);
			//then return it
			fprintf(stdout,returnString);
			//and free memory
			free(returnString);
		}else if(strcmp(command,"clearmemorydump")==0){
			if(clearMemoryDump()){
				fprintf(stdout, "TRUE");
			}else{
				fprintf(stdout, "FALSE");
			}
		}
	}
	
	return 0;
}