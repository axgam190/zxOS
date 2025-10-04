all:
	nasm -f elf32 src/asm/multiboot.asm -o out/multiboot.o
	nasm -f elf32 src/asm/boot.asm		-o out/boot.o

	gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -Iinclude -Wall -Wextra -c src/c/kernel.c -o out/kernel.o
	gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -Iinclude -Wall -Wextra -c src/c/io/framebuffer.c -o out/framebuffer.o

	ld -m elf_i386 --nmagic -T linker.ld -o iso/boot/kernel.bin out/multiboot.o out/boot.o out/framebuffer.o out/kernel.o

	grub-mkrescue -o os.iso iso