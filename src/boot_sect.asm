[org 0x7c00]

bits 16	

mov bx, TEST
call print

call print_nl

call print

jmp $

%include "boot_sect_print.asm"

TEST:
    db 'test OS', 0

; Fill with 510 zeros minus the size of the previous code
times 510-($-$$) db 0
; Magic number
dw 0xaa55 