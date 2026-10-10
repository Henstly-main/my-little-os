// kmain.c
#include "io.h"
#include "drivers/serial.h"
#include "drivers/fb_write.h"
#include "stdio.h"




int kmain(){
    fb_configure_color_attribute(FB_WHITE, FB_BLACK);    
    serial_configure_com1_port(CONF_DIVISOR, CONF_8N1_LINE_PORT, CONF_FIFO_PORT, CONF_MODEM_PORT);
    
    if(serial_is_thre_fifo_empty(SERIAL_COM1_BASE) == 0x20){
        fb_print("COM1 READY!!!");
    }else{
        fb_print("COM1 NOT READY!!!");
    }

    serial_data_port_pushl("Hello from kernel!");

    return 0;
}


