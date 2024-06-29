#include "../drivers/screen.h"
#include "../drivers/text.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"
#include "../cpu/timer.h"
#include "../drivers/keyboard.h"

void update();
void draw_vert_line(int x, int y0, int y1, color color);

int x = 0, y = 0;

void kernel_main(){
    isr_install();

    asm volatile("sti");
    init_timer(100);
    init_keyboard();
    init_screen();

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

    draw_vert_line(0, 0, SCREEN_HEIGHT, color);


    screen_swap();

    if(keyboard_keys[KEY_D])x+=10;
    if(keyboard_keys[KEY_A])x-=10;
    if(keyboard_keys[KEY_W])y-=10;
    if(keyboard_keys[KEY_S])y+=10;

    if(x > SCREEN_WIDTH)x = 0;
}

void draw_vert_line(int x, int y0, int y1, color color){
    while(y0 <= y1){
        put_pixel(x, y0++, color);
    }
}