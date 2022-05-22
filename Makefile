CP := cp
RM := rm -rf
MKDIR := mkdir -pv
MV := mv

BIN = kernel
CFG = grub.cfg
ISO_PATH := iso
BOOT_PATH := $(ISO_PATH)/boot
GRUB_PATH := $(BOOT_PATH)/grub

.PHONY: all
all: bootloader kernel linker iso
	@echo Make has completed.

bootloader: boot/x86/boot.asm
	nasm -f elf32 boot/x86/boot.asm -o boot.o

kernel: kernel/kernel.c
	gcc -m32 -c kernel/kernel.c -o kernel.o
	
linker: linker.ld boot.o kernel.o
	ld -m elf_i386 -T linker.ld -o kernel boot.o kernel.o

iso: kernel
	$(MKDIR) $(GRUB_PATH)
	$(CP) $(BIN) $(BOOT_PATH)
	$(CP) $(CFG) $(GRUB_PATH)
	grub-file --is-x86-multiboot $(BOOT_PATH)/$(BIN)
	grub-mkrescue -o antique.iso $(ISO_PATH)

.PHONY: clean
clean:
	$(RM) *.o