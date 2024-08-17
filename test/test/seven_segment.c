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
	
	
	SET_BIT(DDRA,PIN3);
	SET_BIT(DDRA,PIN2);
	SET_BIT(DDRB,PIN5);
	SET_BIT(DDRB,PIN6);
	
	DDRB |=0b00010111;
	
	
	//SET_BIT(DDRA,2);
	//SET_BIT(DDRA,3);
	//SET_BIT(DDRB,5);
	//SET_BIT(DDRB,6);
	//PORTB&=0b11101000;
	//SET_BIT(DDRB,0);
	//SET_BIT(DDRB,1);
	//SET_BIT(DDRB,2);
	//SET_BIT(DDRB,4);
}

void seven_segment_display(int num)
{
	PORTB &= 0b11101000;

	PORTB |= (((num%10 & 0b00001000)<<1)|(num%10 & 0b00000111));

}
void clear_seven_seg(void)
{
	SET_BIT(PORTB,6);
	SET_BIT(PORTB,5);
	SET_BIT(PORTA,2);
	SET_BIT(PORTA,3);
}
