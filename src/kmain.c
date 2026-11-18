// kmain.c
#include "io.h"
#include "drivers/serial.h"
#include "drivers/fb_write.h"
#include "stdio.h"
#include "cpu/gdt.h"
#include "cpu/lgdt.h"




int kmain(){
    fb_configure_color_attribute(FB_WHITE, FB_BLACK);    
    serial_configure_com1_port(CONF_DIVISOR, CONF_8N1_LINE_PORT, CONF_FIFO_PORT, CONF_MODEM_PORT);
    
    if(serial_is_thre_fifo_empty(SERIAL_COM1_BASE) == 0x20){
        fb_print("COM1 READY!!!");
    }else{
        fb_print("COM1 NOT READY!!!");
    }

    serial_data_port_pushl("Hello from kernel!\n");

    _Static_assert(sizeof(DESCRIPTOR)==8,"Invalid size of  descriptor");
    _Static_assert(sizeof(GDTR)==6, "Invalid size of GDTR register");


    GDT[0] = init_descriptor(0x0,0x0,0x0,0x0);
    
    GDT[1] = init_descriptor(0x00000000, 0xFFFFF, 0x9A, 0xC);
    
    GDT[2] = init_descriptor(0x00000000, 0xFFFFF, 0x92, 0xC);
    //configure_descriptor(&kernel_code_descriptor, 0x00000000, 0xFFFFF, 0x9A, 0xC);
    configure_gdtr(&gdtr_reg);
    serial_data_port_pushl("BEFORE GDT\n");
    load_gdt(&gdtr_reg);
    fb_write("GDT LOADED!!!")
    serial_data_port_pushl("GDT LOADED");
    //configure_descriptor(&kernel_data_descriptor, 0x00000000, 0xFFFFF, 0x92, 0xC);
    return 0;
}


