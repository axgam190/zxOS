/*

framebuffer.c

Written by axgam190 for zxOS.
Handles framebuffer pixel IO (Setting a pixel on screen, Getting a pixel on screen)
Definitions for framebuffer.h

*/

#include "types/multiboot.h"
#include "io/framebuffer.h"
#include "types/stdint.h"

void fb_init(mb_info_t* mb_info, fb_t* fb_ins) {
    fb_ins->addr        = mb_info->fb->fb_addr;
    fb_ins->bpp         = mb_info->fb->fb_bpp;
    fb_ins->height      = mb_info->fb->fb_height;
    fb_ins->width       = mb_info->fb->fb_width;
    fb_ins->pitch       = mb_info->fb->fb_pitch;
    fb_ins->type        = mb_info->fb->fb_type;

    for (int i = 0; i < 6; i++) {
        fb_ins->color_info[i]   = mb_info->fb->fb_color_info[i];
    }

}

void fb_putpx(fb_t* fb_ins, uint16_t x, uint16_t y, uint32_t color) {
    uint8_t* pixel_addr = (uint8_t*)(uint32_t)fb_ins->addr + y * fb_ins->pitch + x * (fb_ins->bpp / 8);

    *(uint32_t*)pixel_addr = color;
}

void fb_getpx(fb_t* fb_ins, uint32_t* color) {

}

void fb_clrscr(fb_t* fb_ins, uint32_t color) {
    for (int x = 0; x < fb_ins->width; x++) {
        for (int y = 0; y < fb_ins->height; y++) {
            fb_putpx(fb_ins, x, y, color);
        }
    }
}