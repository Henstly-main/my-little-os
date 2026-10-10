; loader.s
global loader

MAGIC_NUMBER equ 0x1badb002
FLAGS equ 0x0
CHECKSUM equ -MAGIC_NUMBER
KERNEL_STACK_SIZE equ 16384

section .multiboot
align 4
    dd MAGIC_NUMBER
    dd FLAGS
    dd CHECKSUM


section .bss:
    align 4

section .text
kernel_stack:
    resb KERNEL_STACK_SIZE

loader:
    mov esp, kernel_stack+KERNEL_STACK_SIZE

    extern kmain
    
    call kmain
    

.loop:
    jmp .loop