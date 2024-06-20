/*
 * Fifst_LAB.c
 *
 * Created: 10/7/2022 9:11:33 PM
 * Author : Ahmed khaled
 */ 

#include "DATA_TYPES.h"
#include "DIO_INTERFACE.h"
#include "DIO.h"
#include "LCD.h"
#include "LCD_INTERFACE.h"
#define F_CPU 16000000
#include <util/delay.h>

int main(void)
{
     DIO_SET_PIN_DIRECTION(C, pin2, 1);
     DIO_SET_PIN_DIRECTION(C, pin7, 1);
	 DIO_SET_PIN_DIRECTION(D, pin3, 1);
	 while (1)
	 {
	 DIO_SET_PIN(C, pin2);
	  DIO_SET_PIN(C, pin7);
	  DIO_SET_PIN(D, pin3);
	  _delay_ms(100);
	 DIO_CLEAR_PIN(C, pin2);
	  _delay_ms(100);
	  LCD_INIT();
	  LCD_WRITE_STRING("KHALAF");
	 }
	


}

