/*
 * seven_segment.c
 *
 * Created: 5/24/2023 10:22:13 PM
 *  Author: fadiw
 */ 


#define F_CPU (16000000UL)
#include <util/delay.h>
#include "seven_segment.h"
#include "BIT_MATH.h"

void seven_segment_init(void)
{
	SET_BIT(DDRA,3);
	DDRB |= 0b00010111;
}

void seven_segment_display(int num)
{
	PORTB &= 0b11101000;

	PORTB |= (((num & 0b00001000)<<1)|(num & 0b00000111));

}