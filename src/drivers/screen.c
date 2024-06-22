#include "screen.h"

void put_pixel(int x, int y, color c){

    VIDEO_MEM[(y*SCREEN_WIDTH+x)*3] = c.b; 
    VIDEO_MEM[(y*SCREEN_WIDTH+x)*3+1] = c.g; 
    VIDEO_MEM[(y*SCREEN_WIDTH+x)*3+2] = c.r; 
}

void clear_screen(){
    memset((void*)VIDEO_MEM, 0, SCREEN_WIDTH*SCREEN_HEIGHT*BYTES_PER_PIXEL);
}