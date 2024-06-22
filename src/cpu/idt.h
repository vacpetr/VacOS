#ifndef IDT_H
#define IDT_H

#include "types.h"

#define KERNEL_CS 0x08
#define IDT_ENTRIES 256

typedef struct{
    u16 low_offset;
    u16 selector;
    u8 zero;
    u8 flags;
    u16 high_offset;
} PACKED IDT_entry;

typedef struct{
    u16 limit;
    u32 base;
} PACKED IDT_register;

typedef struct{
    IDT_entry idt_entries[IDT_ENTRIES];
    IDT_register idt_reg;
}IDT;


void set_idt_gate(int n, u32 handler);
void set_idt();

#endif