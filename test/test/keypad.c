/*
 * keypad.c
 *
 * Created: 4/11/2023 6:44:34 PM
 *  Author: SaMir Ahmed
 */ 
#include "keypad.h"
#include "lcd1.h"

const unsigned char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}};

	
void keypad_init()
{
	/* Set pins column as input"*/
	CLR_BIT (DDRD, PIN7) ;
	CLR_BIT (DDRD, PIN6) ;
	CLR_BIT (DDRD, PIN5) ;
	CLR_BIT (DDRD, PIN3);
	/* Set pins of Rows as output"*/
	SET_BIT (DDRC, PIN5);
	SET_BIT (DDRC, PIN4);
	SET_BIT (DDRC, PIN3);
	SET_BIT (DDRC, PIN2);
	/* set col pull up */
	SET_BIT(PORTD, PIN7);
	SET_BIT (PORTD, PIN6);
	SET_BIT (PORTD, PIN5);
	SET_BIT (PORTD, PIN3);
};

unsigned char keypad_get_value()
{
	unsigned char col, row, ans = INVALID_KEYPAD_PRESS;
	for (row=5; row>=2; row--)
	{
		PORTC|=0b00111100;
		CLR_BIT(PORTC,row);
		for(col=7;col>=3;col--)
		{
			if(col==4)
			col--;
			if(GET_BIT(PIND,col)==0)
			{
				_delay_ms(200);
				if(GET_BIT(PIND,col)==0)
				{
					if(col==3)
					{
						
						ans=arr[5-row][7-col-1];
						break;
					}
					else
					{
						ans=arr[5-row][7-col];
						break;
					}
				}
			}
		}
	}
	return ans;
}

// 0 1 2 3		7 8 9 %
// 4 5 6 7		4 5 6 -
// 8 9 10 11	1 2 3 +

int write_to_lcd(){
	int test= INVALID_KEYPAD_PRESS;
	unsigned char value;
	value=keypad_get_value();
	if (value!=INVALID_KEYPAD_PRESS){
		if(value==0){
			lcd_write_char('7');
			test=7;
		}
		else if (value==1)
		{
			lcd_write_char('8');
			test=8;
		}
		else if (value=='2')
		{
			lcd_write_char('9');
			test=9;
		}   else if (value=='3')
		{
			lcd_write_char('0');
			test='0';
		}
	}
	return test;
	
}