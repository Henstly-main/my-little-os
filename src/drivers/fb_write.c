// fb_write.c
#include "../io.h"
#include "fb_write.h"

FRAMEBUFFER frame_buffer = {.base=(volatile char*)0x000B8000, .curr=(volatile char*)0x000B8000, .size=(unsigned short)(FB_ROWS*FB_COLS)};

VGA_CELL fb_cell = {.character=' ', .attribute=0x0F};

void fb_write_cell(volatile char* fb, unsigned short i, VGA_CELL cell){
    fb[i] = cell.character;
    fb[i+1] = cell.attribute; //((bg & 0x0F) << 4) | (fg & 0x0F);
    fb_move_cursor(i+1);
    frame_buffer.curr++;
}

void fb_move_cursor(unsigned short pos){
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, (pos >> 8) & 0x00FF);
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, pos & 0x00FF);
}

