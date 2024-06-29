#ifndef SCREEN_H
#define SCREEN_H

#include "../cpu/types.h"
#include "../libc/util.h"

#define VIDEO_MEM ((u8*)0xFD000000)

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define BYTES_PER_PIXEL 3
#define SCREEN_SIZE (SCREEN_WIDTH*SCREEN_HEIGHT*BYTES_PER_PIXEL)

typedef struct{
    u8 r;
    u8 g;
    u8 b;
}color;

extern u8* sBuffer;

void put_pixel(int x, int y, color c);
void clear_screen();
void screen_swap();
void init_screen();

#endif