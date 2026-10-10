// stdio.c
#include "stdio.h"

/*=====SERIAL COM PORT DRIVER=====*/

/*=====SERIAL COM PORT DRIVER=====*/




/*=====FRAMEBUFFER DRIVER=====*/
FRAMEBUFFER* frame_buffer_ptr = &frame_buffer;

VGA_CELL* fb_cell_ptr = &fb_cell;

unsigned short fb_print(const char* str){
    for(int i = 0; str[i]!='\0'; i++){
        fb_cell_ptr->character = str[i];
        fb_write_cell(frame_buffer_ptr->curr, frame_buffer_ptr->curr-frame_buffer_ptr->base, fb_cell);
    }
    return 0;
}

void fb_configure_color_attribute(unsigned char fg, unsigned char bg){
    fb_cell_ptr->attribute = ((bg & 0x0F) << 4) | (fg & 0x0F); 
}


unsigned int fb_lenstr(const char* str){
    unsigned int i = 0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}

void fb_clean_buf(unsigned short len){
    volatile VGA_CELL* temp_cell = (volatile VGA_CELL*)frame_buffer_ptr->base;
    for(;len--!=0;){
        temp_cell->character = ' ';
        temp_cell->attribute = 0x0F;

        temp_cell++;
    }
    frame_buffer_ptr->curr = frame_buffer_ptr->base;
    fb_move_cursor(0);
}
/*=====FRAMEBUFFER DRIVER=====*/