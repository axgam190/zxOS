/*

kernel.c

Written by axgam190 for zxOS.
kernel.c is responsible for initializing all the core modules provided in the binary,
and to run the Init process from the file system (if found)

*/

#include "types/stdint.h"
#include "types/multiboot.h"
#include "io/framebuffer.h"

void kernel_main(uint32_t magic, uint32_t mbi_address) {
    if (magic != 0x36d76289) return;

    mb_tag_t* tag = (mb_tag_t*)(mbi_address + 8);
    mb_info_t mbi_info = {0}; 

    while (tag->type != 0) {
        switch (tag->type) {
            case MB_TAG_TYPE_CMDLINE:
                mbi_info.cmdline   = (mb_tag_cmdline_t*)tag;  
                break;
            case MB_TAG_TYPE_MODULES:
                mbi_info.modules   = (mb_tag_modules_t*)tag;
                break;
            case MB_TAG_TYPE_FB:
                mbi_info.fb        = (mb_tag_fb_t*)tag;
                break;
        }

        tag = (mb_tag_t*)((uint32_t)tag + ((tag->size + 7) & ~7));
    }

    fb_t fb_ins;

    fb_init(&mbi_info, &fb_ins);
    fb_putpx(&fb_ins, 100, 100, 0x00FF0000);
    fb_putpx(&fb_ins, 100, 101, 0xAAFF0000);
    fb_putpx(&fb_ins, 100, 102, 0x00FFFF00);
    fb_putpx(&fb_ins, 100, 103, 0x00FFFFFF);
    fb_putpx(&fb_ins, 100, 104, 0x00FF00FF);
    fb_putpx(&fb_ins, 100, 105, 0x00AAFF22);
    
}