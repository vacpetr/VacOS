#include "timer.h"
#include "../drivers/ports.h"
#include "../drivers/text.h"
#include "../drivers/screen.h"
#include "isr.h"
#include "types.h"

timer_struct timer;

static void timer_callback(registers_t regs){
    timer.tick++;  
}

void init_timer(u32 freq){
    timer.freq = freq;

    register_interrupt_handler(IRQ0, timer_callback);

    u16 d = (u16) (CLOCK_FREQUENCY / freq);

    u8 low  = (u8)(d & 0xFF);
    u8 high = (u8)( (d >> 8) & 0xFF);

    port_byte_out(0x43, 0x36); //set mode
    port_byte_out(0x40, low); 
    port_byte_out(0x40, high);
}