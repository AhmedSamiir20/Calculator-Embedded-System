
#include "LED.h"

void LED_init(){
	// set the four leds as output
	SET_BIT(DDRA,PIN4);
	SET_BIT(DDRA,PIN5);
	SET_BIT(DDRA,PIN6);
	SET_BIT(DDRB,PIN7);
	
	//clear the port value for leds to turn all off
	CLR_BIT(PORTA,PIN4);
	CLR_BIT(PORTA,PIN5);
	CLR_BIT(PORTA,PIN6);
	CLR_BIT(PORTB,PIN7);
	
	_delay_ms(15);
}
void LED_on(unsigned char chr){
	if (chr==4)
	{
		SET_BIT(PORTA,PIN4);
	}
	else if (chr==3)
	{
		SET_BIT(PORTA,PIN5);
	}
	else if (chr==2)
	{
		SET_BIT(PORTA,PIN6);
	}
	else if (chr==1)
	{
		SET_BIT(PORTB,PIN7);
	}
}

void LED_off(unsigned char chr){
	if (chr==4)
	{
		CLR_BIT(PORTA,PIN4);
	}
	else if (chr==3)
	{
		CLR_BIT(PORTA,PIN5);
	}
	else if (chr==2)
	{
		CLR_BIT(PORTA,PIN6);
	}
	else if (chr==1)
	{
		CLR_BIT(PORTB,PIN7);
	}
}

void LED_toggle(unsigned char chr){
	if (chr==4)
	{
		TOGGLE_BIT(PORTA,PIN4);
	}
	else if (chr==3)
	{
		TOGGLE_BIT(PORTA,PIN5);
	}
	else if (chr==2)
	{
		TOGGLE_BIT(PORTA,PIN6);
	}
	else if (chr==1)
	{
		TOGGLE_BIT(PORTB,PIN7);
	}
}