/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>

int main (void)
{
	system_init();

	/* Insert application code here, after the board has been initialized. */
	
	
	struct port_config config;
	config.direction = PORT_PIN_DIR_INPUT;
	port_pin_set_config(PIN_PA02, &config);
	
	
	while(1)
	{
		printf("tick %d \n", port_pin_get_input_level(PIN_PA02));
		delay_ms(1000);
		printf("tock %d \n", port_pin_get_input_level(PIN_PA02));
		delay_ms(1000);
	}
}
