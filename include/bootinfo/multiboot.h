/*

multiboot.h

Basic multiboot_info structure to use in kernel.c and all OS programs.

*/

#ifndef MULTIBOOT_H
#define MULTIBOOT_H

#include "types/stdint.h"

#define MB_TAG_TYPE_CMDLINE 1
#define MB_TAG_TYPE_MODULES 3
#define MB_TAG_TYPE_FB      8

typedef struct mb_tag {
    uint32_t type;
    uint32_t size;
} mb_tag_t;

typedef struct mb_tag_cmdline {
    mb_tag_t tag;
    char string[];
} mb_tag_cmdline_t;

typedef struct mb_tag_modules {
    mb_tag_t tag;
    uint32_t mod_start;
    uint32_t mod_end;
    char string[];
} mb_tag_modules_t;

typedef struct mb_tag_fb {
    mb_tag_t tag;
    uint64_t fb_addr;
    uint32_t fb_pitch;
    uint32_t fb_width;
    uint32_t fb_height;
    uint8_t fb_bpp;
    uint8_t fb_type;
    uint8_t fb_reserved;
    uint8_t fb_color_info[6];
} mb_tag_fb_t;

typedef struct mb_info {
    uint32_t total_size;
    uint32_t reserved;

    mb_tag_cmdline_t   *cmdline;
    mb_tag_modules_t   *modules;
    mb_tag_fb_t        *fb;
} mb_info_t;

#endif