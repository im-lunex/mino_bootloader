CC      = gcc
CFLAGS  = -ffreestanding -m32 -nostdlib -nostdinc \
           -fno-builtin -fno-stack-protector -Wall

LDFLAGS = -m elf_i386 -T linker.ld --oformat=elf32-i386

all: myos.iso

kernel.elf: src/kernel.c
	$(CC) $(CFLAGS) -c src/kernel.c -o kernel.o
	ld $(LDFLAGS) -o kernel.elf kernel.o

myos.iso: kernel.elf
	mkdir -p iso/boot/grub
	cp kernel.elf iso/boot/kernel.elf
	cp grub/grub.cfg iso/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso iso/

run: myos.iso
	qemu-system-x86_64 -cdrom myos.iso -display gtk

clean:
	rm -rf *.o *.elf *.iso iso/
