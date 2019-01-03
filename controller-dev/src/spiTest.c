#include <wiringPi.h>
#include <mcp23s17.h>
#include <stdio.h>

int main(){
	wiringPiSetup();
	mcp23s17Setup(256,1,7);
	for(int i = 0 ; i < 16; i++){
		pinMode(256+i, OUTPUT);
		digitalWrite(256+i,0);
	}
	while(1){
	digitalWrite(264,1);
	digitalWrite(264,0);
	}
/*	while(1){
	printf("%d\n",digitalRead(256));}*/
}
