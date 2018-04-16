/*
 * uart.c
 *
 * Created: 13/04/2018 14:45:58
 *  Author: Olly
 */ 

#include <asf.h>

struct usart_module usart_instance;
#define MAX_RX_BUFFER_LENGTH   5
volatile uint8_t rx_buffer[MAX_RX_BUFFER_LENGTH];

void system_usart_init(void)
{
	/* Initialise UART & stdio */
	configure_usart();
	configure_usart_callbacks();
	system_interrupt_enable_global();
}

void usart_read_callback(struct usart_module *const usart_module)
{
	usart_write_buffer_job(&usart_instance,
	(uint8_t *)rx_buffer, MAX_RX_BUFFER_LENGTH);
}
void usart_write_callback(struct usart_module *const usart_module)
{
	//port_pin_toggle_output_level(LED_0_PIN);
}


void configure_usart(void)
{
	struct usart_config config_usart;
	usart_get_config_defaults(&config_usart);
	config_usart.baudrate    = 9600;
	config_usart.mux_setting = USART_RX_1_TX_0_XCK_1;
	config_usart.pinmux_pad0 = PINMUX_UNUSED;
	config_usart.pinmux_pad1 = PINMUX_UNUSED;
	config_usart.pinmux_pad2 = PINMUX_PA22C_SERCOM3_PAD0;		// Tx PA22 (HU PCB SDA)
	config_usart.pinmux_pad3 = PINMUX_PA23C_SERCOM3_PAD1;		// Rx PA23 (HU PCB SCL)
	while (usart_init(&usart_instance,
	SERCOM3, &config_usart) != STATUS_OK) {
	}
	usart_enable(&usart_instance);
	
	
	stdio_serial_init(&usart_instance, SERCOM3, &config_usart);
}



void configure_usart_callbacks(void)
{
	usart_register_callback(&usart_instance,
	usart_write_callback, USART_CALLBACK_BUFFER_TRANSMITTED);
	usart_register_callback(&usart_instance,
	usart_read_callback, USART_CALLBACK_BUFFER_RECEIVED);
	usart_enable_callback(&usart_instance, USART_CALLBACK_BUFFER_TRANSMITTED);
	usart_enable_callback(&usart_instance, USART_CALLBACK_BUFFER_RECEIVED);
}

