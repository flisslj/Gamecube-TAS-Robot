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

boolean isRunning;

/**
* running main has some format
* first flag - UART or ethernet (1 if using ethernet)
* second flag - base filepath
*/
int main(int argc, char *argv[]){
	
	//first, we make sure we have enough arguments
	if(argc<3){
		printf("Not enough arguments! Need UART/Ethernet and base filepath.\n");
		return 0;
	}
	
	
	char type = *(argv[1]);
	char* basePath = argv[2];
	char* command = malloc(sizeof(char)*MAX_STDIN_CMD_LENGTH);
	size_t len = 0;
	command = "abort"; //this is a default in case command goes wrong
	
	contInit();
	
	//by default, the program is not running
	isRunning = false;
	
	//handles grabbing and returns commands through stdin
	if(type=='0'){
		//UART setup is surprisingly simple
		serialOpen("/dev/ttyAMA0", UART_BAUD);
	}
	
	while(1){
		//spinlock until we get a command
		//this means functions like run should be interrupt-driven
		//unless we can slap interrupts on this in which case nvm
		int n = 0;
		if(type=='1'){
			while(n==0){
				if (ioctl(0, I_NREAD, &n) == 0 && n > 0){
					getline(&command,&len,stdin);
				}else{
					if(isRunning){
						contRun();
					}
				}
			}
		}else if(type=='0'){
			while(serialDataAvail(fileDesc)==0 || serialDataAvail(fileDesc)==-1){
				if(isRunning){
					contRun();
				}
			}
			read(fileDesc,command, MAX_STDIN_CMD_LENGTH);
		}else{
			printf("%c",type);
		}
		//we now have a command, let's parse it
		if(strcmp(command,"help\n")==0){
			generalPrint(type,"List of commands:\n");
			generalPrint(type,"heartbeat, hardware\n");
			generalPrint(type,"sdsize, sdopen, loadiso\n");
			generalPrint(type,"getfiles, getisos, gettases\n");
			generalPrint(type,"getcurrenttas, getcurrentiso\n");
			generalPrint(type,"loadtas, settas, setiso\n");
			generalPrint(type,"run, abort, and help, ya silly\n");
		}else if(strcmp(command,"hardware\n")==0){
			uint64_t ret = getAttachedHardware();
			//encode ret into base 64
			char* returnString = malloc(sizeof(char)*17);
			//sprintf(returnString,"%"PRIx64"\n",ret);
			
			longToBase64(ret,returnString);
			*(returnString + LONG_TO_BASE64_LENGTH) = '\n';
			//then return it
			
			generalPrint(type,returnString);
			//and free memory
			free(returnString);
		}else if(strncmp(command,"heartbeat:",10)==0){
			//we then grab the variable and then determine whether to return error or confirmation
			//TODO
		}else if(strcmp(command,"sdsize\n")==0){
			uint64_t ret = getSDsize();
			//encode ret into base 64
			char* returnString = malloc(sizeof(char)*LONG_TO_BASE64_LENGTH+1);
			longToBase64(ret,returnString);
			*(returnString + LONG_TO_BASE64_LENGTH) = '\n';
			//then return it
			generalPrint(type,returnString);
			//and free memory
			free(returnString);
		}else if(strcmp(command,"sdopen\n")==0){
			uint64_t ret = getSDEmptySpace();
			//encode ret into base 64
			//encode ret into base 64
			char* returnString = malloc(sizeof(char)*LONG_TO_BASE64_LENGTH+1);
			longToBase64(ret,returnString);
			*(returnString + LONG_TO_BASE64_LENGTH) = '\n';
			//then return it
			generalPrint(type,returnString);
			//and free memory
			free(returnString);
		}else if(strcmp(command,"getfiles\n")==0){
			generalPrint(type,getFiles(basePath));
		}else if(strcmp(command,"getisos\n")==0){
			generalPrint(type,getISOs(basePath));
		}else if(strcmp(command,"gettases\n")==0){
			generalPrint(type,getTASes(basePath));
		}else if(strcmp(command,"getcurrentiso\n")==0){
			generalPrint(type,getCurrentISO(basePath));
		}else if(strcmp(command,"getcurrenttas\n")==0){
			generalPrint(type,getCurrentTAS(basePath));
		}else if(strncmp(command,"settas:",7)==0){
			//move the pointer over 7
			if(setTAS(command + 7)){
				generalPrint(type, "TRUE\n");
			}else{
				generalPrint(type, "FALSE\n");
			}
		}else if(strncmp(command,"setiso:",7)==0){
			//move the pointer over 7
			if(setISO(command + 7)){
				generalPrint(type, "TRUE\n");
			}else{
				generalPrint(type, "FALSE\n");
			}
		}else if(strncmp(command,"loadiso:",8)==0){
			//move the pointer over 8
			if(loadISO(command + 8)){
				generalPrint(type, "TRUE\n");
			}else{
				generalPrint(type, "FALSE\n");
			}
		}else if(strncmp(command,"loadtas:",8)==0){
			//move the pointer over 8
			if(loadTAS(command + 8)){
				generalPrint(type, "TRUE\n");
			}else{
				generalPrint(type, "FALSE\n");
			}
		}else if(strcmp(command,"run\n")==0){
			isRunning = true;
			generalPrint(type, "TRUE\n");
		}else if(strcmp(command,"abort\n")==0){
			if(contAbort()){
				generalPrint(type, "TRUE\n");
				isRunning = false;
			}else{
				generalPrint(type, "FALSE\n");
			}
			return 0;
		}else if(strcmp(command,"getmemorydump\n")==0){
			//TODO 
			//generalPrint(type, getMemoryDump());
		}else if(strcmp(command,"getmemorydumpdata\n")==0){
			uint64_t ret = getMemoryDumpData();
			//encode ret into base 64
			char* returnString = malloc(sizeof(char)*LONG_TO_BASE64_LENGTH+1);
			longToBase64(ret,returnString);
			*(returnString + LONG_TO_BASE64_LENGTH) = '\n';
			//then return it
			generalPrint(type,returnString);
			//and free memory
			free(returnString);
		}else if(strcmp(command,"clearmemorydump\n")==0){
			if(clearMemoryDump()){
				generalPrint(type, "TRUE\n");
			}else{
				generalPrint(type, "FALSE\n");
			}
		}else{
			generalPrint(type, "incorrect command\n");
		}
	}
	
	return 0;
}

void generalPrint(char type, char* message){
	if(type=='1'){
		fprintf(stdout,message);
	}else if(type=='0'){
		serialPrintf(fileDesc,message);
	}
}
