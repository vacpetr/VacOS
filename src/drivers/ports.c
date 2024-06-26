#include "ports.h"

//read byte from port
u8 port_byte_in (u16 port) {
    u8 result;

    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

//input byte into port
void port_byte_out (u16 port, u8 data){
    __asm__ __volatile__("out %%al, %%dx" : : "a" (data), "d" (port));
}

//read word from port
u16 port_word_in (u16 port) {
    u16 result;
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}

//input word to port
void port_word_out (u16 port, u16 data) {
    __asm__ __volatile__("out %%ax, %%dx" : : "a" (data), "d" (port));
}