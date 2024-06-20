#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include "DATA_TYPES.h"


/*define LCD commands*/
#define clear_lcd				0X01
#define shift_cursor_r			0X14
#define shift_cursor_l			0X10
#define first_line_begin		0X80
#define second_line_begin		0Xc0
#define mode_8bit				0X38
#define mode_4bit				0X02
#define mode_4bit_dot_matrix	0x28
#define display_on				0X0C


void LCD_INIT(void);
void LCD_WRITE_STRING(u8* buffer);
void LCD_WRITE_CHAR(u8 CHAR);
void REVERSE_STRING(u8* buffer);
void CONVERT_DECIMAL_TO_SREING(u32 dec, u8* buffer);
void LCD_WRITE_INT(u32 value);
void LCD_WRITE_COMMAND(u8 command);
void LCD_SET_CURSOR_POSITION(u8 x, u8 y); // starts from (0, 0)
void LCD_PEEK(void);


#endif /*LCD_INTERFACE_H*/