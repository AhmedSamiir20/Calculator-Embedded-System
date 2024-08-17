/*
 * lcd1.c
 *
 * Created: 4/8/2023 2:28:32 PM
 *  Author: TECHNO
 */ 
#include "lcd1.h"
void Lcd_write_int(int value)
{
	char buffer[16];
	itoa(value, buffer, 10);
	lcd_string(buffer);
}
void lcd_inti(void)
{
	SET_BIT(lcd_command_DDR ,RS);
	SET_BIT(lcd_command_DDR ,E);
	
	SET_BIT(lcd_data_DDR ,0);
	SET_BIT(lcd_data_DDR ,1);
	SET_BIT(lcd_data_DDR ,2);
	SET_BIT(lcd_data_DDR ,4);
	
	_delay_ms(15);
	lcd_command(0x02);
	lcd_command(0x28); //4bit mode
	
	lcd_command(0x0c); // display on and set cursor
	lcd_command(0x01);//delete any thing in LCD
	lcd_command(0x80);// set cursor in star
}
void lcd_command(unsigned char cmd)
{
	CLR_BIT(lcd_command_port,RS); // 1111 0000
	
	lcd_data_port&=0b11101000; //delete data on pin 1,2,4
	
	 unsigned char high=((cmd&0xf0)>>4)	;    //shift the last 4bit in first =0000 1111
	                      // 00010000 
	  unsigned char temp =(((high&0b00001000)<<1)|(high&0b00000111));
	  lcd_data_port|=temp; // the highest part send to register
	  //latch to the high 4bit
	  CLR_BIT(lcd_command_port,E);
	  SET_BIT(lcd_command_port,E);
	  _delay_ms(1);
	  CLR_BIT(lcd_command_port,E);
	  _delay_ms(5);
	  //////////////send the least 4bit/////////////
	  PORTB&=0b11101000; //delete data on pin 1,2,4
	  
	  unsigned char low=((cmd&0x0f))	;    //shef the last 4bit in frist =0000 1111
	  // 00010000
	  unsigned char temp2 =(((low&0b00001000)<<1)|(low&0b00000111));
	  lcd_data_port|=temp2; // the highest patr send to register
	  //latch to the high 4bit
	  CLR_BIT(lcd_command_port,E);
	  SET_BIT(lcd_command_port,E);
	  _delay_ms(1);
	  CLR_BIT(lcd_command_port,E);
	  _delay_ms(5);
}
void lcd_write_char(unsigned char ch)
{
	SET_BIT(lcd_command_port,RS); // 1111 0000
	
	 lcd_data_port&=0b11101000; //delete data on pin 1,2,4
	
	unsigned char high=((ch&0xf0)>>4)	;    //shef the last 4bit in frist =0000 1111
	// 00010000
	unsigned char temp =(((high&0b00001000)<<1)|(high&0b00000111));
	lcd_data_port|=temp; // the highest patr send to register
	//latch to the high 4bit
	CLR_BIT(lcd_command_port,E);
	SET_BIT(lcd_command_port,E);
	_delay_ms(1);
	CLR_BIT(lcd_command_port,E);
	//////////////send the least 4bit/////////////
	lcd_data_port&=0b11101000; //delete data on pin 1,2,4
	
	unsigned char low=((ch&0x0f))	;    //shef the last 4bit in frist =0000 1111
	// 00010000
	unsigned char temp2 =(((low&0b00001000)<<1)|(low&0b00000111));
	lcd_data_port|=temp2; // the highest patr send to register
	//latch to the high 4bit
	CLR_BIT(lcd_command_port,2);
	SET_BIT(lcd_command_port,2);
	_delay_ms(1);
	CLR_BIT(lcd_command_port,2);
	_delay_ms(5);	
}
void lcd_string(unsigned char* srt)
{
	for(int i=0; srt[i] !='\0';i++ )
{
	lcd_write_char(srt[i]);
}
	}
	void lcd_clear()
	{
		lcd_command(0x01);
	}