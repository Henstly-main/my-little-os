#include "io.h"

#define FB_GREEN             2
#define FB_DARK_GREY    8

#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND      15

#define FB_COMMAND_PORT    0x3D4
#define FB_DATA_PORT    0x3D5

void fb_write_cell(volatile char* fb,unsigned int i, char c, unsigned char fg, unsigned char bg){
    fb[i] = c;
    fb[i+1] = ((bg & 0x0F) << 4) | (fg & 0x0F);
}

void fb_move_cursor(unsigned short pos){
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, pos & 0x00FF);
}

int kmain(int arg1, int arg2){
    volatile char* fb = (volatile char*)0x000B8000;
   fb_write_cell(fb,0, 'A', FB_GREEN, FB_DARK_GREY);
   fb_move_cursor(1);
    
    return arg1+arg2;
}


