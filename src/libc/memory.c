#include "memory.h"

u32 free_mem_addr = 0x00100000;

u32 kmalloc(u32 size, u8* phys_addr){
    u32 ret = free_mem_addr;

    if(phys_addr) *phys_addr = free_mem_addr;

    free_mem_addr += size;

    return ret;
}

void memset(void *dst, u8 val, u32 size){
    u32 num_dwords = size/4;
    u32 num_bytes = size%4;
    u32 *dest32 = (u32*)dst;
    u32 *dest8 = ((u32*)dst)+num_dwords*4;

    u32 val8 = (u8)val;
    u32 val32 = val|(val<<8)|(val<<16)|(val<<24);

    u32 i;

    for (i=0;i<num_dwords;i++) {
        dest32[i] = val32;
    }
    for (i=0;i<num_bytes;i++) {
        dest8[i] = val8;
    }

}

void memcpy(void *dst, void *src, u32 size){
    u32 num_dwords = size/4;
    u32 num_bytes = size%4;
    u32 *dest32 = (u32*)dst;
    u32 *src32 = (u32*)src;
    u32 *dest8 = ((u32*)dst)+num_dwords*4;
    u32 *src8 = ((u32*)src)+num_dwords*4;
    u32 i;

    for (i=0;i<num_dwords;i++) {
        dest32[i] = src32[i];
    }

    for (i=0;i<num_bytes;i++) {
        dest8[i] = src8[i];
    }


}