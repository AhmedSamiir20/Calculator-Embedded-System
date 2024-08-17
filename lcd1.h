/*
 * lcd1.h
 *
 * Created: 4/8/2023 2:28:01 PM
 *  Author: TECHNO
 */ 


#ifndef LCD1_H_
#define LCD1_H_
#define F_CPU 8000000

#define lcd_data_DDR    DDRB
#define lcd_command_DDR  DDRA


#define lcd_data_port    PORTB
#define lcd_command_port  PORTA

#define  RS  3
#define  E  2

#include "Register.h"
#include "BIT_MATH.h"
#include <util/delay.h>
void lcd_inti(void);
void lcd_command(unsigned char cmd);
void lcd_write_char(unsigned char ch);
void lcd_string(unsigned char* srt);
void lcd_clear();
void Lcd_write_int(int value);

#endif /* LCD1_H_ */