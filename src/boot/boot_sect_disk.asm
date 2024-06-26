;dh - number of tracks to load
;bx - memory addres to load in 

disk_load:
    pusha
    push dx

    mov ah, 0x02
    mov al, 18
    mov cl, 0x02

    mov ch, 0x00
    mov dh, 0x00



.disk_loop:
    int 0x13
    jc disk_error

    mov cl,1
    inc ch

    cmp ch, dh
    jne .disk_loop

.done:
    pop dx

    popa
    ret


sectors_error:
    mov bx, SECTORS_ERROR
    call print

disk_loop:
    jmp $


disk_error:
    mov bx, DISK_ERROR
    call print
    call print_nl
    jmp disk_loop

DISK_ERROR: db "Disk read error", 0
SECTORS_ERROR: db "Incorrect number of sectors read", 0