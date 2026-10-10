// stdio.h
#ifndef STDIOH
#define STDIOH
#include "io.h"
#include "drivers/fb_write.h"
#include "drivers/serial.h"

//#define sizeof(type)            ((char *)((type *)0 + 1) - (char *)(type *)0)

unsigned short fb_print(const char* str);

unsigned int fb_lenstr(const char* str);

void fb_clean_buf(unsigned short len);

void fb_configure_color_attribute(unsigned char fg, unsigned char bg);

#endif