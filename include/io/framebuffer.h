/*

framebuffer.h

Written by axgam190 for zxOS.
Handles framebuffer pixel IO (Setting a pixel on screen, Getting a pixel on screen)
Blueprint for framebuffer.c

*/

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "types/stdint.h"
#include "types/multiboot.h"

typedef struct fb {
    uint64_t addr;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint8_t bpp;
    uint8_t type;
    uint8_t color_info[6];
} fb_t;

void fb_init(mb_info_t* mb_info, fb_t* fb_ins);
void fb_putpx(fb_t* fb_ins, uint16_t x, uint16_t y, uint32_t color);
void fb_getpx(fb_t* fb_ins, uint32_t* color);
void fb_clrscr(fb_t* fb_ins, uint32_t color);

#endif