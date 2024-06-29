C_SOURCES = $(wildcard src/kernel/*.c src/drivers/*.c src/cpu/*.c src/libc/*.c)
HEADERS = $(wildcard src/kernel/*.h src/drivers/*.h src/cpu/*.h src/libc/*.h)
# Nice syntax for file extension replacement
OBJ = ${C_SOURCES:.c=.o src/cpu/interrupt.o}

# Change this if your cross-compiler is somewhere else
CC=i686-elf-gcc

# -g: Use debugging symbols in gcc
CFLAGS = -g

all: kernel.bin iso clean

# '--oformat binary' deletes all symbols as a collateral, so we don't need
# to 'strip' them manually on this case
kernel.bin: src/boot/kernel_entry.o ${OBJ}
	i686-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary
	nasm -f bin src/boot/boot_sect.asm -o boot_sect.bin

# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -Wall -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

iso:
	dd if=/dev/zero of=boot.iso bs=512 count=2880
	dd if=boot_sect.bin of=boot.iso conv=notrunc bs=512 seek=0 count=1
	dd if=kernel.bin of=boot.iso conv=notrunc bs=512 seek=1 count=2048

clean:
	rm -rf src/kernel/*.o src/cpu/*.o src/boot/*.bin src/drivers/*.o src/boot/*.o src/libc/*.o
