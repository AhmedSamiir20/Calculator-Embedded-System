/*
 * test.c
 *
 * Created: 5/25/2023 6:57:15 PM
 * Author : lenovo
 */ 

#include <avr/io.h>
#include "BIT_MATH.h"
#include "keypad.h"
#include "lcd1.h"
#include "LED.h"
#include "Register.h"
#include "seven_segment.h"


int charToDigit(char c){
	if(c>='0' && c<='9'){
		return (int)(c-'0');
	}
	else
		return -1;
	
}

void countDown_in_sec(int lie)
{
	
	lcd_string("Counting Down !!");
	for(int i=0; i<lie;i++)
	{
		disply_num(i);
		_delay_ms(1000);
	}
	
	lcd_clear();
}

void countDown_in_min(int lie)
{
	lcd_string("Counting Down !!");
	for(int i=0; i<lie;i++)
	{
		disply_num(i);
		_delay_ms(60000);
	}
	lcd_clear();
}

void countDown_in_hour(int lie)
{
	lcd_string("Counting Down !!");
	for(int i=0; i<lie;i++)
	{
		disply_num(i);
		_delay_ms(360000);
	}
	lcd_clear();
}

void Toggle_Leds()
{
	for(int i=0;i<5;i++)
	{
		LED_toggle(1);
	    LED_toggle(2);
		LED_toggle(3);
		LED_toggle(4);
		_delay_ms(500);
	}
}

void Buzzer_on(){
	SET_BIT(DDRC,6);
	for(int i=0;i<5;i++){
		SET_BIT(PORTC,6);
		_delay_ms(1000);
		CLR_BIT(PORTC,6);
		Toggle_Leds();
	}
	lcd_string("BEEEEEEb !!");
	lcd_clear();
	_delay_ms(1000);
	lcd_string("BEEEEEEb !!");
	lcd_clear();
	
	lcd_clear();
	_delay_ms(1000);
	lcd_string("BEEEEEEb !!");
	lcd_clear();
	
	lcd_clear();
	_delay_ms(1000);
	lcd_string("BEEEEEEb !!");
	lcd_clear();
	lcd_string("BEW BEW Ahmed Mohsen BEW BEW !!");
}

   void disply_num(int num)
   {
	   int digit4=(num/1000)%10;
	   int digit3=(num/100)%10;
	   int digit2=(num/10)%10;
	   int digit1=(num/1)%10;
     //display the digits on the four-digit seven-segment display
	 uint16_t start_time =0;
	 while(start_time<1000)//delay for 1 second
	 {
		 seven_segment_display(digit4);
		 _delay_ms(1);
		 TOGGLE_BIT(PORTB,6);
		 seven_segment_display(digit3);
		  _delay_ms(1);
	  TOGGLE_BIT(PORTB,5);
	   seven_segment_display(digit2);
	    _delay_ms(1);
		TOGGLE_BIT(PORTA,2);
		seven_segment_display(digit1);
		 _delay_ms(1);
		 TOGGLE_BIT(PORTA,3);
		 start_time +=5;
		
     } 

 }



int main(void)
{
	lcd_inti();
	keypad_init();
	seven_segment_init();
	LED_init();
	unsigned char num;
	int num_time;
	int temp=0;
	int do_time;
	int in_sec=0;
	int in_min=0;
	int in_hour=0;
	//DDRC=0xff;
	//PORTC=0b11111100;
	


	//SET_BIT(DDRC,7);
	//SET_BIT(PORTC,7);
	//SET_BIT(DDRC,8);
	//SET_BIT(PORTC,8);
	
    /* Replace with your application code */
	lcd_string("Choose Mode : ");
    while (1) 
    {
	
		num=keypad_get_value();
		if(num !=INVALID_KEYPAD_PRESS){
			num_time=charToDigit(num);
			if(num_time>=0 &&num_time<=9)
			{
					temp*=10;
					temp+=num_time;
			}
			
			if(num=='c'){
				lcd_clear();
				lcd_string("Resting...");
				_delay_ms(1000);
				lcd_clear();
				lcd_string("Resting...");
				_delay_ms(1000);
				lcd_clear();
				num_time=0;
				temp=0;
				in_min=0;
				in_sec=0;
				in_hour=0;
				num=INVALID_KEYPAD_PRESS;
				lcd_string("Choose Mode : ");
			}
				
			lcd_write_char(num);
			if(num=='/')
			{
				lcd_clear();
				lcd_string("Enter Time In Sec : ");
				in_sec=1;
				
			}
			if(num=='*')
			{
				lcd_clear();
				lcd_string("Enter Time In Min : ");
				in_min=1;
				
			}
			if(num=='-')
			{
					lcd_clear();
					lcd_string("Enter Time In hour : ");
					in_hour=1;
					
			}
			
			if(num=='=')
			{
				do_time=temp;
			lcd_clear();	
			//_delay_ms(10000);
			if(in_min==1)
			{
				countDown_in_min(do_time);
				//Toggle_Leds();
				Buzzer_on();
			}
			else if(in_hour==1)
			{
				countDown_in_hour(do_time);
				//Toggle_Leds();
				Buzzer_on();
			}
			else if(in_sec==1)
			{
				countDown_in_sec(do_time);
				//Toggle_Leds();
				Buzzer_on();
			}


			}
		}
		
    }
}

