/*
 * ADC_TESTER.c
 *
 * Created: 11/11/2022 9:46:14 PM
 * Author : Eng Ahmed khaled
 */ 

#include "ADC_Config.h"
#include "DIO_CONFIG.h"

int main(void)
{
	ADC_Init();
	DIO_SetPinDirection(DIO_PORTA, PIN1, DIO_PIN_INPUT);
	DIO_SetPinDirection(DIO_PORTC, PIN2, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC, PIN7, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTD, PIN3, DIO_PIN_OUTPUT);
	
	u16 RETURNDigitalValue, analog;
    /* Replace with your application code */
    while (1) 
    {
		ADC_GetDigitalVal(&RETURNDigitalValue, ADC_CHANNEL1);
         
		analog = ((u32)RETURNDigitalValue * 5000UL) / 1024;
		
		if (analog < 1500)
		{
			
			DIO_PinValue(DIO_PORTC, PIN2, HIGH);
			DIO_PinValue(DIO_PORTC, PIN7, LOW);
			DIO_PinValue(DIO_PORTD, PIN3, LOW);
			
		}
		else if (analog < 3000)
		{
			DIO_PinValue(DIO_PORTC, PIN2, LOW);
			DIO_PinValue(DIO_PORTC, PIN7, HIGH);
			DIO_PinValue(DIO_PORTD, PIN3, LOW);
		}
		else if (analog < 4500)
		{
			DIO_PinValue(DIO_PORTC, PIN2, LOW);
			DIO_PinValue(DIO_PORTC, PIN7, LOW);
			DIO_PinValue(DIO_PORTD, PIN3, HIGH);
		}
		
	}
}

