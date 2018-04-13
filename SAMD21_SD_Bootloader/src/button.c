
/*
 * button.c
 *
 * Created: 13/04/2018 16:17:03
 *  Author: Olly
 */ 

#include "asf.h"

#include "button.h"

void system_button_init(void)
{
	struct port_config config;
	config.direction = PORT_PIN_DIR_INPUT;
	port_pin_set_config(BUTTON_PIN, &config);
}

bool readButton(void)
{
	port_pin_get_input_level(BUTTON_PIN);
}