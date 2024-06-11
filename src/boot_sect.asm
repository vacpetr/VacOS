[org 0x7c00]

bits 16	

mov bp, 0x8000 ; set the stack safely away from us
mov sp, bp

mov bx, 0x1000 ; es:bx = 0x0000:0x9000 = 0x09000
mov dh, 1

call disk_load

mov bx, TEST
call print

call print_nl

call print

jmp 0x1000

%include "src/boot_sect_print.asm"
%include "src/boot_sect_disk.asm"

TEST:
    db 'test OS', 0

; Fill with 510 zeros minus the size of the previous code

times 510-($-$$) db 0
; Magic number
dw 0xaa55 

mov al, 'A'
mov ah, 0x0e
int 0x10

mov eax, 0x1000
jmp eax