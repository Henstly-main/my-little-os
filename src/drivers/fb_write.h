// fb_write.h
#ifndef FB_INCLUDEH
#define FB_INCLUDEH

#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND      15

#define FB_COMMAND_PORT               0x3D4
#define FB_DATA_PORT                     0x3D5

#define FB_ROWS                               25
#define FB_COLS                               80

#define FB_BLACK                               0
#define FB_BLUE                                1
#define FB_GREEN                              2
#define FB_TURQUOISE                     3
#define FB_RED                                  4
#define FB_PURPLE                            5
#define FB_BROWN                              6
#define FB_LIGHT_GREY                   7
#define FB_DARK_GREY                     8
#define FB_LIGHT_BLUE                   9
#define FB_LIGHT_GREEN                 10 // 0xA
#define FB_LIGH_TURQUOISE          11 // 0xB
#define FB_LIGHT_RED                     12 // 0xC
#define FB_LIGHT_PURPLE               13 // 0xD
#define FB_LIGHT_BROWN                 14 // 0xE
#define FB_WHITE                             15  // 0xF

#define FB_CELL_SIZE                    2

typedef struct {
    volatile char* base;
    volatile char* curr;
    unsigned short size;
} FRAMEBUFFER;

typedef struct {
    char character;     
    char attribute;     
} __attribute__((packed)) VGA_CELL;

void fb_write_cell(volatile char* fb,unsigned short i, VGA_CELL cell);

void fb_move_cursor(unsigned short pos);

extern FRAMEBUFFER frame_buffer;

extern VGA_CELL fb_cell;

#endif