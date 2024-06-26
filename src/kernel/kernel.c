#include "../drivers/screen.h"
#include "../drivers/text.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"
#include "../cpu/timer.h"
#include "../drivers/keyboard.h"

void update();

int x = 0, y = 0;

void main(){
    isr_install();

    //x = 5/0;

    asm volatile("sti");
    init_timer(20);
    init_keyboard();

    int last_tick = timer.tick;

    while(true){

        if(last_tick != timer.tick){
            update();
            last_tick = timer.tick;
        }
        
    }
}

void update(){
    clear_screen();
    color color = {255,0,0};

    for(int xx = 0; xx < 100; xx++){
        for(int yy = 0; yy < 100; yy++){
            put_pixel(x+xx, y+yy, color);
        }
    }   

    if(keyboard_keys[KEY_D])x+=5;
    if(keyboard_keys[KEY_A])x-=5;
    if(keyboard_keys[KEY_W])y-=5;
    if(keyboard_keys[KEY_S])y+=5;

    if(x > SCREEN_WIDTH)x = 0;




}