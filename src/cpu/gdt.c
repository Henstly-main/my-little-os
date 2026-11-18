// gdt.c
#include "gdt.h"

DESCRIPTOR GDT[DESCRIPTOR_COUNT];

GDTR gdtr_reg;

void configure_descriptor(DESCRIPTOR* descriptor,unsigned int base, unsigned int limit, unsigned char access_byte, unsigned char flags){
    descriptor->base_low = base & 0x0000FFFF;
    descriptor->base_mid = (base & 0x00FF0000)>>16;
    descriptor->base_high = (base & 0xFF000000)>>24;

    limit = limit & 0x000FFFFF;
    flags = (flags & 0x0F)<<4;
    descriptor->limit_low = limit & 0x0000FFFF;
    descriptor->limit_high_flags = ((limit & 0xF0000)>>16) | flags;

    descriptor->access_byte = access_byte;
}

DESCRIPTOR init_descriptor(unsigned int base, unsigned int limit, unsigned char access_byte, unsigned char flags){
    DESCRIPTOR descriptor;
    descriptor.base_low = base & 0x0000FFFF;
    descriptor.base_mid = (base & 0x00FF0000)>>16;
    descriptor.base_high = (base & 0xFF000000)>>24;

    limit = limit & 0x000FFFFF;
    flags = (flags & 0x0F)<<4;
    descriббююа ptor.limit_low = limit & 0x0000FFFF;
    descriptor.limit_high_flags = ((limit & 0xF0000)>>16) | flags;

    descriptor.access_byte = access_byte;
    return descriptor;
}

void configure_gdtr(GDTR* gdtr_ptr){
    gdtr_ptr->base = (unsigned int)GDT;
    gdtr_ptr->limit = sizeof(GDT)-1;
}