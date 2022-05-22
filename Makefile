CP := cp
RM := rm -rf
MKDIR := mkdir -pv

BIN = kernel
CFG = boot/grub.cfg
ISO_PATH := iso
BOOT_PATH := $(ISO_PATH)/boot
GRUB_PATH := $(BOOT_PATH)/grub

.PHONY: all
all: bootloader kernel linker iso
	@echo Make has completed.

bootloader: boot/x86/boot.asm
	nasm -f elf32 boot/x86/boot.asm -o boot.o

kernel: src/kernel.c
	gcc -m32 -c src/*.c
	
linker: linker.ld
	ld -m elf_i386 -T linker.ld -o kernel *.o

iso: kernel
	$(MKDIR) $(GRUB_PATH)
	$(CP) $(BIN) $(BOOT_PATH)
	$(CP) $(CFG) $(GRUB_PATH)
	grub-file --is-x86-multiboot $(BOOT_PATH)/$(BIN)
	grub-mkrescue -o antique.iso $(ISO_PATH)

.PHONY: clean
clean:
	$(RM) *.o