
/*
 * button.h
 *
 * Created: 13/04/2018 16:17:11
 *  Author: Olly
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "asf.h"


#define BUTTON_PIN	PIN_PA02


void system_button_init(void);
bool readButton(void);


#endif	// BUTTON_H_