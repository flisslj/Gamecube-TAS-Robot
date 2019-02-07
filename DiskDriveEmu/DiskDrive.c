#include "DiskDrive.h"

/*
* Author: Robert Gelhar
* File: DiskDrive.c
* Date: 1/30/2019
* 
* The purpose of this file is to give a library of functions relating to the disk drive
* Given a list of pins in the header to define the port being used
* and some interrupts on pins, we can set up a disk drive emulation system with an SD card.
*/

void runDDEmu(){
	
	
	return;
}

void DDInit(){
	//to initialize the disk drive, we first need to set up some pins
	
	//pin directions list below
	//TODO
	//OUT: DD_AISD, DD_AISCLK
	//OUT: DIDSTRB
	//IN: DD_AISLR
	//IN: DIHSTRB, DIDIR
	//IN: DIRSTB, DIERRB, DICOVER, DIBRK
	//BIDIR: DID0, DID1, DID2, DID3, DID4, DID5, DID6, DID7
	//GND: MONI, MONOUT LMFAO
	
	//the default values for all the out pins should be 0
	//TODO
	
	return;
}

boolean readPin(int pinIdent){
	//so the thing is that each ident is the offset you add to gpio
	//pin ident is that the first 6 hex are the gpio offset
	//the last hex is the offset
	
	//an example, like E5, would be 0x10105
	//*(0x40021010)&(1<<5)
	*(uint32_t) ptr = (GPIO_A + pinIdent>>4 + IDR);
	return (*(ptr)&(1<<(pinIdent&0xFF))!=0);
}

char readData(){
	//the byte is E8 to E15
	//so just shift the IDR down
	*(uint32_t) ptr = (GPIO_A + 0x1010);
	return *(ptr)>>8;
}