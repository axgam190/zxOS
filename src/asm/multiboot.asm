; multiboot.asm
section .multiboot_header
header_start:
    dd 0xe85250d6                   ; magic
    dd 0                            ; architecture
    dd header_end - header_start    ; header length
    dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start)) ; checksum

    dw 5        ; type = 5 (framebuffer)
    dw 7        ; flags
    dd 20       ; size
    dd 1024     ; width
    dd 768      ; height
    dd 32       ; bpp

    dw 0
    dw 0
    dd 8
header_end: