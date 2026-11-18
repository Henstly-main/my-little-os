// gdt.h
#ifndef INCLUDE_GDT_H
#define INCLUDE_GDT_H
#define DESCRIPTOR_COUNT        3
#define DATA_SELECTOR               0x10
#define CODE_SELECTOR               0x08
#define NULL_SELECTOR               0x00

typedef struct {
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char base_mid;
    unsigned char access_byte;
    unsigned char limit_high_flags;
    unsigned char base_high;
} __attribute__((packed)) DESCRIPTOR;

typedef struct {
    unsigned short limit;
    unsigned int base;
} __attribute__((packed)) GDTR;

void configure_descriptor(DESCRIPTOR* descriptor, unsigned int base, unsigned int limit, unsigned char access_byte, unsigned char flags);

DESCRIPTOR init_descriptor(unsigned int base, unsigned int limit, unsigned char access_byte, unsigned char flags);

void configure_gdtr(GDTR* gdtr_ptr);


extern DESCRIPTOR GDT[DESCRIPTOR_COUNT];
extern GDTR gdtr_reg;
#endif