#include <stdio.h>
#include <wiringPi.h>
#include <mcp23s17.h>

#define BASE_0 128
#define BASE_1 256

#define OPCODE 0x40
#define READ 0x01

#define SPI_SPEED 10000000 //10 MHZ

#define usingMCPLIB 1

static int STATE = 0;

int main(){
	//we're testing two chips, one that is at 000, one at 001
	
	wiringPiSetup();
	
	if(usingMCPLIB){
		mcp23s17Setup(BASE_0, 0, 0);
		mcp23s17Setup(BASE_1, 1, 1);
		//we'll have both chips output, as a test
		for(int i = 0; i<16; i++){
			pinMode(BASE_0 + i, OUTPUT);
			pinMode(BASE_1 + i, OUTPUT);
		}
	
		//to test operation, we turn on the half of upper bank of both pins, half off
		//honestly just to see wtf is actually going on
		
		for(int i = 8; i < 16; i+=2){
			digitalWrite(BASE_0 + i, 0);
			digitalWrite(BASE_0 + i + 1, 1);
			digitalWrite(BASE_1 + i, 1);
			digitalWrite(BASE_1 + i + 1, 0);
		}
		
		//flicker the rest
		while(1){
		
			for(int i = 0; i < 8; i++){
				digitalWrite(BASE_0 + i, (i&1)^STATE);
				digitalWrite(BASE_1 + i, (i&1)^STATE^1);
			}
		
			STATE ^= 1;
		}
	}else{
		
		//we're going to do this by hand using wiringPI SPI instead
		//this might increase true throughput by like 16, idk
		
		int fd0 = wiringPiSPISetup(0, SPI_SPEED);
		printf("what is fd0? %d \n", fd0);
		int fd1 = wiringPiSPISetup(1, SPI_SPEED);
		printf("what is fd1? %d \n", fd1);
		
		//so now we need to figure out, like, what the hell is actually going on in terms of writing
		//to write to a certain address, we need three bytes in an array
		char* regCMD = malloc(sizeof(char)* 2);
		while(1){
			//first, we make the control byte for MCP0
			*(regCMD) = OPCODE |  ((0x0) << 1); //write operation to 000
			*(regCMD + 1) = 0x12; //address for GPIOA register, the right side
			*(regCMD + 2) = 0xAA; //easy to test
		
			wiringPiSPIDataRW(0,regCMD,3);
		
			//then we run a clear through it
			*(regCMD) = OPCODE |  ((0x0) << 1); //write operation to 000
			*(regCMD + 1) = 0x12; //address for GPIOA register, the right side
			*(regCMD + 2) = 0x00; //easy to test
		
			wiringPiSPIDataRW(0,regCMD,3);
		]
		
		
	}
}