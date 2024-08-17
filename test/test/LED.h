
#ifndef LED_H_
#define LED_H_

#include "BIT_MATH.h"
#include "Register.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void LED_init();
void LED_on(unsigned char chr);
void LED_off(unsigned char chr);
void LED_toggle(unsigned char chr);

#endif /* LED_H_ */