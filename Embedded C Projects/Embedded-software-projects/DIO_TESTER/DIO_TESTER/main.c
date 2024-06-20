/*
 * DIO_TESTER.c
 *
 * Created: 10/28/2022 7:17:36 PM
 * Author : Ahmed khaled khalaf
 */ 

#define  F_CPU 16000000UL
#include <util/delay.h>
#include "DIO_CONFIG.h"

int main(void)
{
    /* Replace with your application code */
	
	DIO_SetPinDirection(DIO_PORTC, PIN2,DIO_PIN_OUTPUT); //LED 0 O/P
	DIO_SetPinDirection(DIO_PORTC, PIN7,DIO_PIN_OUTPUT); //LED 1 O/P
	DIO_SetPinDirection(DIO_PORTD, PIN3,DIO_PIN_OUTPUT); //LED 2 O/P
	
	
	
	DIO_SetPinDirection(DIO_PORTB, PIN0, DIO_PIN_INPUT);
	DIO_SetPinDirection(DIO_PORTD, PIN6, DIO_PIN_INPUT);
	DIO_SetPinDirection(DIO_PORTD, PIN2, DIO_PIN_INPUT);
	
	
	DIO_SetPinDirection(DIO_PORTA, PIN4, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA, PIN5, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA, PIN6, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA, PIN7, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB, PIN1, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB, PIN2, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB, PIN3, DIO_PIN_OUTPUT);
	
	DIO_PinValue (DIO_PORTA, PIN4, HIGH);
	DIO_PinValue (DIO_PORTA, PIN5, LOW);
	DIO_PinValue (DIO_PORTA, PIN6, LOW);
	DIO_PinValue (DIO_PORTA, PIN7, LOW);
	
	DIO_PinValue (DIO_PORTB, PIN1, HIGH);
	DIO_PinValue (DIO_PORTB, PIN2, HIGH);
	DIO_PinValue (DIO_PORTB, PIN3, HIGH);
	u8 SW0_State = 0;
	u8 SW1_State = 0;
	u8 SW2_State = 0;
	
    while (1) 
    {
		SW0_State = DIO_GET_PIN_VALUE(DIO_PORTB, PIN0);
		SW1_State = DIO_GET_PIN_VALUE(DIO_PORTD, PIN6);
		SW2_State = DIO_GET_PIN_VALUE(DIO_PORTD, PIN2);
		
		if (SW0_State == HIGH)
		{
			DIO_PinValue(DIO_PORTC, PIN2, HIGH); //LED 0 ON
			DIO_PinValue(DIO_PORTA, PIN3, HIGH); //buzzer 2 toggle
		}
		else
		{
			DIO_PinValue(DIO_PORTC, PIN2, LOW);
			DIO_PinValue(DIO_PORTA, PIN3, LOW); //buzzer 2 toggle
			
		}
		if (SW1_State == HIGH)
		{
			//_delay_ms(10);
			DIO_PinValue(DIO_PORTC, PIN7, LOW); //LED 1 OFF
		}
		else
		{
			DIO_PinValue(DIO_PORTC, PIN7, HIGH); //LED 1 OFF
		}
		if (SW2_State == HIGH)
		{
			//_delay_ms(500);
				DIO_PinValue(DIO_PORTD, PIN3, HIGH); //LED 2 toggle
				
				
		}
		

    }
}

