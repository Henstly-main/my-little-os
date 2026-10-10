// serial.h
#ifndef SERIALH
#define SERIALH
#include "../io.h"



#define SERIAL_COM1_BASE                                     0x3F8
#define SERIAL_DATA_PORT(base)                        (base)
#define SERIAL_IER_PORT(base)                          (base+1)
#define SERIAL_FIFO_COMMAND_PORT(base)      (base+2)
#define SERIAL_LINE_COMMAND_PORT(base)      (base+3)
#define SERIAL_MODEM_COMMAND_PORT(base)    (base+4)
#define SERIAL_LINE_STATUS_PORT(base)         (base+5)



#define SERIAL_UNABLE_DLAB                                  0x80                               

#define CONF_8N1_LINE_PORT        0x03
#define CONF_FIFO_PORT                 0xC7
#define CONF_MODEM_PORT               0x03
#define CONF_DIVISOR                      0x3

void serial_configure_baud_rate(unsigned short com, unsigned short divisor);

void serial_configure_line(unsigned short com, unsigned short conf);

void serial_configure_fifo(unsigned short com, unsigned short conf);

void serial_configure_modem(unsigned short com, unsigned short conf);

short serial_is_thre_fifo_empty(unsigned short com);

void serial_configure_com1_port(unsigned short divisor,  unsigned short line_conf, unsigned short fifo_conf, unsigned short modem_conf);

void serial_data_port_pushb(const char* c);

void serial_data_port_pushl(const char* str);

#endif