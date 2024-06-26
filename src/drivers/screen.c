#include "screen.h"
#include "text.h"
#include "util.h"

//unsigned char sBuffer[SCREEN_SIZE];

void put_pixel(int x, int y, color c){
    VIDEO_MEM[(y*SCREEN_WIDTH+x)*3] = c.b; 
    VIDEO_MEM[(y*SCREEN_WIDTH+x)*3+1] = c.g; 
    VIDEO_MEM[(y*SCREEN_WIDTH+x)*3+2] = c.r; 
}

void screen_swap(){

    /*for(int i = 1; i < 1024*768; i++){
        sBuffer[i] = 0;
    }*/
    
}


void clear_screen(){
    memset(VIDEO_MEM, 0, SCREEN_SIZE);
}