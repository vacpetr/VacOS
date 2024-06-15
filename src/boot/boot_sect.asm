[org 0x7c00]
KERNEL_OFFSET equ 0x1000

mov bp, 0x8000 ; set the stack safely away from us
mov sp, bp

mov bx, KERNEL_OFFSET ; memory where disk segments are loaded
mov dh, 10 ;number of segments to load

call disk_load ;load sectors from disk

mov bx, TEST 
call print ;print message

call print_nl

mov ax, 0x4F02	
mov bx, 0x4118
int 0x10	

call switch_pm

%include "src/boot/boot_sect_print.asm"
%include "src/boot/boot_sect_disk.asm"
%include "src/boot/boot_sect_gdt.asm"
%include "src/boot/32bit_switch.asm"

;-------------------------------------------------

[bits 32]
begin_pm:
    call KERNEL_OFFSET
    jmp $;

;--------------------------------------------------

TEST: db "test OS", 0

; Fill with 510 zeros minus the size of the previous code

times 510-($-$$) db 0
; Magic number
dw 0xaa55 