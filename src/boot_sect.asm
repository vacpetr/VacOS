[org 0x7c00]

mov bp, 0x8000 ; set the stack safely away from us
mov sp, bp

mov bx, 0x1000 ; memory where disk segments are loaded
mov dh, 1 ;number of segments to load

call disk_load ;load sectors from disk

mov bx, TEST 
call print ;print message

call print_nl

call switch_pm

%include "src/boot_sect_print.asm"
%include "src/boot_sect_disk.asm"
%include "src/boot_sect_gdt.asm"
%include "src/32bit_switch.asm"

;-------------------------------------------------

[bits 32]
begin_pm:
    VIDEO_MEMORY equ 0xb8000
    WHITE_ON_BLACK equ 0x0f 

    mov edx, VIDEO_MEMORY
    mov ah, WHITE_ON_BLACK

    jmp $


;--------------------------------------------------

TEST:
    db 'test OS', 0

; Fill with 510 zeros minus the size of the previous code

times 510-($-$$) db 0
; Magic number
dw 0xaa55 