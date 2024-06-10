run:
	nasm -f bin src/boot_sect.asm -o src/boot_sect.bin
	qemu-system-x86_64 src/boot_sect.bin 