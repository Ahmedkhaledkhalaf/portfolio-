/*
 * KEYPAD_TEST.c
 *
 * Created: 10/29/2022 11:22:37 PM
 * Author : Eng Ahmed khaled
 */ 


#include "KeyPad_Config.h"
#include "KeyPad_interface.h"
#include "DIO_CONFIG.h"
#include "DATA_TYPES.h"



int main(void)
{
	KPD_init();
	
	DIO_SetPinDirection(DIO_PORTA, PIN3, DIO_PIN_OUTPUT); //led0 output
	DIO_SetPinDirection(DIO_PORTC, PIN7, DIO_PIN_OUTPUT); //led1 output
	DIO_SetPinDirection(DIO_PORTD, PIN3, DIO_PIN_OUTPUT); //led2 output
	u8 Data;
	
    /* Replace with your application code */
    while (1) 
    {
		KPD_getvalue(&Data);
		
		if (Data != KPD_NOT_PRESSED)
		{
			if(Data == 4)
			{
				DIO_PinValue(DIO_PORTA, PIN3, HIGH);
				// SSD_displayNOM(Data, SSD_ONE);
			}
			else
			{
				DIO_PinValue(DIO_PORTA, PIN3, LOW);
			}
		}
			
    }
}

