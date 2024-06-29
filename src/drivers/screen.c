#include "screen.h"
#include "text.h"
#include "../libc/memory.h"

u8* sBuffer;

void put_pixel(int x, int y, color c){
    sBuffer[(y*SCREEN_WIDTH+x)*3] = c.b; 
    sBuffer[(y*SCREEN_WIDTH+x)*3+1] = c.g; 
    sBuffer[(y*SCREEN_WIDTH+x)*3+2] = c.r; 
}

void screen_swap(){

    memcpy(VIDEO_MEM, sBuffer, SCREEN_SIZE);
    
}

void clear_screen(){
    memset(sBuffer, 0, SCREEN_SIZE);
}

void init_screen(){
    sBuffer = (u8*)kmalloc(SCREEN_SIZE, sBuffer);

    memset((void*)sBuffer, 0, SCREEN_SIZE);
    memset(VIDEO_MEM, 0, SCREEN_SIZE);
}