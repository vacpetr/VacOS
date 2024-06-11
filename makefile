compile:
	nasm -f bin src/boot_sect.asm -o src/boot_sect.bin

	dd if=/dev/zero of=boot.iso bs=512 count=100
	dd if=src/boot_sect.bin of=boot.iso conv=notrunc bs=512 seek=0 count=2

	qemu-system-x86_64 -drive file=boot.iso,format=raw,index=0