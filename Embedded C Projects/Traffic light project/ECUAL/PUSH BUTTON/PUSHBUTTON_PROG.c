/*
 * PUSHBUTTON_PROG.c
 *
 * Created: 11/9/2022 8:09:51 PM
 *  Author: Eng Ahmed khaled
 */ 
#include "PUSHBUTTON_Config.h"


//initialize
void BUTTON_init(u8 ButtonPortID, u8 ButtonPinID)
{
	DIO_SetPinDirection(ButtonPortID, ButtonPinID, DIO_PIN_INPUT);
}

void BUTTON_read(u8 portname, u8 pinnum, u8* result){
	*result = DIO_GET_PIN_VALUE(portname, pinnum);
}

