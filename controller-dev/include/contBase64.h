#ifndef BASE64_CONT_H
#define BASE64_CONT_H

#define LONG_TO_BASE64_LENGTH 11

#include <stdint.h>

const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void longToBase64(uint64_t source, char* dest);

uint64_t base64Len(uint64_t arrLength);

void byteArrToBase64(uint8_t* arr, uint64_t arrLen, char* dest);

#endif