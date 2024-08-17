/*
 * keypad.h
 *
 * Created: 4/11/2023 6:44:11 PM
 *  Author: SaMir Ahmed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "BIT_MATH.h"
#include "Register.h"
#define F_CPU (16000000UL)

#include <util\delay.h>
#define INVALID_KEYPAD_PRESS (0xFF)

void keypad_init();
unsigned char keypad_get_value();

int write_to_lcd(void);



#endif /* KEYPAD_H_ */