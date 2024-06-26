#ifndef UTIL_H
#define UTIL_H

#include "../cpu/types.h"

void memset(void* dst, u8 value, u32 size);
void memcpy(void* dst, void* src, u32 size);

void int_to_string(u32 val, char* str);
int strlen(char* str);
void reverse_string(char* str);

#endif