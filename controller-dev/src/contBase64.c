#include "contBase64.h"
static char contBase64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void longToBase64(uint64_t source, char* dest){
	for(int i = 0; i < LONG_TO_BASE64_LENGTH; i++){
		//to grab the big endian digit, you first shift all the irrelevant digits
		//then, you mod 64 to cut off the higher digits
		*(dest+i) = contBase64_table[(source>>(60-6*i))%64];
	}
	
	return;
}

uint64_t base64Len(uint64_t arrLength){
	//3 chars is 4 base64 digits
	//the remainder bit is due to this tabling here
	// 1 char, 2 digits
	// 2 char, 3 digits
	// 3 char, 4 digits
	// 4 char, 6 digits
	return (4*arrLength)/3 + (arrLength%3==0)?(0):(1);
}

void byteArrToBase64(uint8_t* arr, uint64_t arrLen, char* dest){
	switch(arrLen%3){
		case 2: //with two characters, we use three digits
			// 001234 | 567812 | 345678
			*(dest) = contBase64_table[arr[0]>>4];
			*(dest+1) = contBase64_table[((arr[0]%(1<<4))<<2) + (arr[1]>>6)];
			*(dest+2) = contBase64_table[arr[1]%(1<<6)];
			dest += 3;
			arrLen -= 2;
			arr += 2;
			break;
		case 1: //with one character, we use two digits for that character
			// 000012 | 34568
			*(dest) = contBase64_table[(arr[0]>>6)];
			*(dest+1) = contBase64_table[(arr[0]%(1<<6))];
			dest += 2;
			arrLen--;
			arr++;
			break;
	}
	
	//after this switch-case, everything is now 3-byte aligned, and ready for looping
	
	for(int i = 0; i < 4*arrLen/3; i += 4){
		//three bytes form four 6-bit digits
		// 123456 | 781234 | 567812 | 345678
		*(dest+i) = contBase64_table[(arr[i]>>2)];
		*(dest+i+1) = contBase64_table[((arr[i]%(1<<2))<<6) + (arr[i+1]>>4)];
		*(dest+i+2) = contBase64_table[(arr[i+1]%(1<<4))+(arr[i+2]>>6)];
		*(dest+i+3) = contBase64_table[arr[i+2]%(1<<6)];
	}
	
	return;
}