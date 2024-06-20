/*
 * SSD_interface.c
 *
 * Created: 10/28/2022 10:36:16 PM
 *  Author: Eng Ahmed khaled
 */ 
#include "DIO_CONFIG.h"
#include "SSD_CONFIG.h"
#include "DATA_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 16000000UL
#include <util/delay.h>


void SSD_INIT(void)
{
	DIO_SetPinDirection(DIO_PORTB, PIN1, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB, PIN2, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB, PIN3, DIO_PIN_OUTPUT);
	
	DIO_SetPinDirection(DIO_PORTA, PIN4, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA, PIN5, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA, PIN6, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA, PIN7, DIO_PIN_OUTPUT);
}



void SSD_displayNOM(u8 desired_number, u8 ssdId)
{
	switch(ssdId)
	{
		case SSD_ONE:
		DIO_PinValue(DIO_PORTB, PIN2, HIGH);
		SSD_WriteHalfPort(desired_number);
		break;
		case SSD_TWO:
		DIO_PinValue(DIO_PORTB, PIN1, HIGH);
		SSD_WriteHalfPort(desired_number);
		break;
	}
	
}


void SSD_WriteHalfPort(u8 Value)
{
	if (GET_BIT(Value, 0) == 1)
	{
		DIO_PinValue(DIO_PORTA, PIN4, HIGH);
	}
	else
	{
		DIO_PinValue(DIO_PORTA, PIN4, LOW);
	}
	
	if (GET_BIT(Value, 1) == 1)
	{
		DIO_PinValue(DIO_PORTA, PIN5, HIGH);
	}
	else
	{
		DIO_PinValue(DIO_PORTA, PIN5, LOW);
	}
	
	if (GET_BIT(Value, 2) == 1)
	{
		DIO_PinValue(DIO_PORTA, PIN6, HIGH);
	}
	else
	{
		DIO_PinValue(DIO_PORTA, PIN6, LOW);
	}
	
	if (GET_BIT(Value, 3) == 1)
	{
		DIO_PinValue(DIO_PORTA, PIN7, HIGH);
	}
	else
	{
		DIO_PinValue(DIO_PORTA, PIN7, LOW);
	}
	
}


void SSD_DisplayMultiNom(u8 num)
{
	DIO_PinValue(DIO_PORTB, PIN2, LOW);
	DIO_PinValue(DIO_PORTB, PIN1, LOW);
	
	SSD_WriteHalfPort(num/10);
	DIO_PinValue(DIO_PORTB, PIN2, HIGH);
	_delay_ms(10);
	DIO_PinValue(DIO_PORTB, PIN2, LOW);

	SSD_WriteHalfPort(num%10);
	DIO_PinValue(DIO_PORTB, PIN1, HIGH);
		_delay_ms(10);
	DIO_PinValue(DIO_PORTB, PIN1, LOW);


}