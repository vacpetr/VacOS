#include "keyboard.h"
#include "ports.h"
#include "../cpu/isr.h"
#include "text.h"
#include "util.h"

bool keyboard_keys[NUM_OF_KEYS];

static void keyboard_callback(registers_t regs){
    u8 scancode = port_byte_in(KEYBOARD_PORT);
    color color = {255,0,0};
    keyboard_keys[(u8) (scancode & 0x7F)] = KEY_IS_PRESS(scancode);

}

void init_keyboard() {

   register_interrupt_handler(IRQ1, keyboard_callback);

}