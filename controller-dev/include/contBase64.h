/**
* contBase64.h
* Robert Gelhar, Senior Design MSOE
* 12/3/2018
* 
* Header for base64 converter, as all solutions online included incompatible licensing
* Only does the encoding, not the decoding - there should be no reason to decode
*/

#ifndef BASE64_CONT_H
#define BASE64_CONT_H

#define LONG_TO_BASE64_LENGTH 	11 //64 bits / 6 (bits/digit) = 11 digits (rounded)

#include <stdint.h>

void longToBase64(uint64_t source, char* dest);

uint64_t base64Len(uint64_t arrLength);

void byteArrToBase64(uint8_t* arr, uint64_t arrLen, char* dest);

#endif