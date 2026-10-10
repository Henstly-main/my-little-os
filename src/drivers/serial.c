// serial.c
#include "../io.h"
#include "serial.h"


void serial_configure_com1_port(unsigned short divisor,  unsigned short line_conf, unsigned short fifo_conf, unsigned short modem_conf){
    serial_configure_baud_rate(SERIAL_COM1_BASE, divisor);
    serial_configure_line(SERIAL_COM1_BASE, line_conf);
    serial_configure_fifo(SERIAL_COM1_BASE, fifo_conf);
    serial_configure_modem(SERIAL_COM1_BASE, modem_conf);
}

void serial_configure_baud_rate(unsigned short com, unsigned short divisor){
    outb(SERIAL_LINE_COMMAND_PORT(com),SERIAL_UNABLE_DLAB);
    outb(SERIAL_IER_PORT(com), (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com), divisor & 0x00FF);
}

void serial_configure_fifo(unsigned short com, unsigned short conf){
    outb(SERIAL_FIFO_COMMAND_PORT(com), conf & 0x00FF);
}

void serial_configure_modem(unsigned short com, unsigned short conf){
    outb(SERIAL_MODEM_COMMAND_PORT(com), conf & 0x00FF);
}

void serial_configure_line(unsigned short com, unsigned short conf){
    outb(SERIAL_LINE_COMMAND_PORT(com), conf);
}

short serial_is_thre_fifo_empty(unsigned short com){
    return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

void serial_data_port_pushb(const char* c){
    outb(SERIAL_DATA_PORT(SERIAL_COM1_BASE), *c);
}

void serial_data_port_pushl(const char* str){
    while(*str!='\0'){
        while(serial_is_thre_fifo_empty(SERIAL_COM1_BASE) != 0x20){};
        serial_data_port_pushb(str++);
    }
}