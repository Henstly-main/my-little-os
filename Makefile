OBJECTS = loader.o kmain.o io.o
CC = gcc
CFLAGS = -m32 -c -ffreestanding -nostdlib \
				 -fno-builtin -fno-stack-protector \
				 -nostartfiles -nodefaultlibs -Wall \
				 -Wextra -Werror

LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -g -F dwarf -f elf32

.PHONY: all run clean

VPATH = src

all: kernel.elf


kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf 
	GRUB_MKRESCUE_SED_STRIP="d" grub-mkrescue -d /usr/lib/grub/i386-pc/ -o os.iso iso

run: os.iso
	qemu-system-i386 -s -S -cdrom os.iso


%.o: %.c
	$(CC) $(CFLAGS)		$< -o $@

%.o: %.s
	$(AS) $(ASFLAGS)  $< -o $@

#clean:
#	rm -rf *.o kernel.elf os.iso
#	nasm -g -F dwarf -f elf32 src/loader.s
#	gcc -m32 -c src/kmain.c -o src/kmain.o -ffreestanding -nostdlib -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs
#	ld -g -T link.ld -melf_i386 src/loader.o src/kmain.o -o kernel.elf
	
	

	
	

clean:
	rm -f $(OBJECTS) kernel.elf os.iso src/kmain.o