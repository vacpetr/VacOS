#include "../drivers/screen.h"
#include "../drivers/text.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"

void main(){
    isr_install();

    
}