#include "idt.h"

IDT idt;

void set_idt_gate(int n, u32 handler) {
    idt.idt_entries[n].low_offset = low_16(handler);
    idt.idt_entries[n].selector = KERNEL_CS;
    idt.idt_entries[n].zero = 0;
    idt.idt_entries[n].flags = 0x8E; 
    idt.idt_entries[n].high_offset = high_16(handler);
}

void set_idt() {
    idt.idt_reg.base = (u32)&idt.idt_entries;
    idt.idt_reg.limit = IDT_ENTRIES * sizeof(IDT_entry) - 1;

    __asm__ __volatile__("lidtl (%0)" : : "r" (&idt.idt_reg));
}