#ifndef MEMORY_H
#define MEMORY_H

#include "../cpu/types.h"

u32 kmalloc(u32 size, u8* phys_addr);

void memset(void* dst, u8 val, u32 size);
void memcpy(void* dst, void* src, u32 size);

#endif