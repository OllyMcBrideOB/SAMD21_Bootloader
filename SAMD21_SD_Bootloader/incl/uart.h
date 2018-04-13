/*
 * uart.h
 *
 * Created: 13/04/2018 14:47:13
 *  Author: Olly
 */ 


#ifndef UART_H_
#define UART_H_

#include <asf.h>

void system_usart_init(void);
void configure_usart(void);
void configure_usart_callbacks(void);
void usart_read_callback(struct usart_module *const usart_module);
void usart_write_callback(struct usart_module *const usart_module);


#endif // UART_H_