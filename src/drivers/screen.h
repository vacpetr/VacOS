#ifndef SCREEN_H
#define SCREEN_H

#include "../cpu/types.h"
#include "util.h"

#define VIDEO_MEM ((unsigned char*)0xFD000000)

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define BYTES_PER_PIXEL 3

typedef struct{
    u8 r;
    u8 g;
    u8 b;
}color;

void put_pixel(int x, int y, color c);
void clear_screen();

#endif