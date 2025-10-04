; boot.asm
global start
extern kernel_main

section .text
bits 32
align 4
start:
    call kernel_main
end:
    hlt
    jmp end