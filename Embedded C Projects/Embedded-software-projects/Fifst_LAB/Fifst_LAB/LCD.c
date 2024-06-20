#include "LCD.h"
#include "LCD_INTERFACE.h"
#include "DATA_TYPES.h"
#include "DIO_INTERFACE.h"

#define F_CPU	12000000
#include <util/delay.h>

void LCD_INIT(void)
{
	/*set data and control pins direction to be output*/
	DIO_WRITE_DDR(A, (1<<RS) | (1<<E) | (1<<D4) | (1<<D5) | (1<<D6) | (1<<D7));
	
	/*set the initial value for the enable bin low */
	DIO_CLEAR_PIN(A, E);
	
	/*delay 20 ms for LCD to be ready*/
	_delay_ms(20);
	
	LCD_WRITE_COMMAND(mode_4bit);
	
	/*set the LCD in 8 bits mode*/
	LCD_WRITE_COMMAND(mode_4bit_dot_matrix);
	
	/*turn display on and cursor off*/
	LCD_WRITE_COMMAND(display_on);
	
	/*clear the LCD*/
	LCD_WRITE_COMMAND(clear_lcd);
	
	/*set the cursor to the begin of the next line*/
	LCD_WRITE_COMMAND(first_line_begin);
	
	/*say hi*/
	LCD_WRITE_STRING("Amar Mohamed  :)");
	_delay_ms(3000);
	LCD_WRITE_COMMAND(clear_lcd);
	
	/*set the cursor to the begin of the next line*/
	LCD_WRITE_COMMAND(first_line_begin);
}


void LCD_SET_CURSOR_POSITION(u8 x, u8 y)
{
	LCD_WRITE_COMMAND(0x80 | (x+ 64 * y));
}


void LCD_WRITE_STRING(u8* buffer)
{
	u32 i = 0;
	while(buffer[i] != '\0')
	{
		LCD_WRITE_CHAR(buffer[i]);
		i++;
	}
}


void LCD_WRITE_CHAR(u8 CHAR)
{
	/*send upper nipple*/
	DIO_WRITE_PORT(A, (CHAR >> 4) | (DIO_READ_PORT(A) & 0XF0));
	DIO_SET_PIN(B, RS);
	LCD_PEEK();
	_delay_ms(1);
	
	/*send lower nipple*/
	DIO_WRITE_PORT(A, (CHAR & 0X0F) | (DIO_READ_PORT(A) & 0XF0));
	DIO_SET_PIN(A, RS);
	LCD_PEEK();
	_delay_ms(2);
}


void LCD_WRITE_INT(u32 value)
{
	u8 buffer[20];
	CONVERT_DECIMAL_TO_SREING(value, buffer);
	LCD_WRITE_STRING(buffer);
}


void CONVERT_DECIMAL_TO_STREING(u32 dec, u8* buffer)
{
	if(dec == 0)
	{
		buffer[0] = 0;
		buffer[1] = '\0';
	}
	else
	{
		u8 i = 0;
		u8 reminder = 0;
		
		while(dec != 0)
		{
			reminder = dec % 10;
			dec = dec / 10;
			buffer[i] = 48 + reminder;
			i++;
		}
		buffer[i] = '\0';

		REVERSE_STRING(buffer);
	}
	
}




void REVERSE_STRING(u8* buffer)
{
	u8 x = 0;
	while(buffer[x] != '\0') x++;
	
	u8 buffer_end = x-1;
	u8 buffer_center = buffer_end/2;
	
	u8 i = 0;
	while(i <= buffer_center)
	{
		u8 temp = buffer[i];
		buffer[i] = buffer[buffer_end - i];
		buffer[buffer_end - i] = temp;
		i++;
	}
}


void LCD_WRITE_COMMAND(u8 command)
{
	/*send upper nipple*/
	DIO_WRITE_PORT(A, (command >> 4) | (DIO_READ_PORT(A) & 0XF0));
	DIO_CLEAR_PIN(A, RS);
	LCD_PEEK();
	_delay_ms(1);
	
	/*send lower nipple*/
	DIO_WRITE_PORT(A, (command & 0X0F) | (DIO_READ_PORT(A) & 0XF0));
	DIO_CLEAR_PIN(A, RS);
	LCD_PEEK();
	_delay_ms(2);
}


void LCD_PEEK(void)
{
	DIO_SET_PIN(A, E);
	_delay_us(2);
	DIO_CLEAR_PIN(A, E);
}