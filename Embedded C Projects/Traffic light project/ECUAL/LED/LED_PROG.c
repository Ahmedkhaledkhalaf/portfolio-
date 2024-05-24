/*
 * LED_PROG.c
 *
 * Created: 11/9/2022 7:56:01 PM
 *  Author: Eng Ahmed khaled
 */ 
#include "LED_Config.h"

void LED_init(u8 LedPortID,u8 LedPinID)
{
	DIO_SetPinDirection(LedPortID,LedPinID,DIO_PIN_OUTPUT);
}

void LED_on(u8 LedPortID,u8 LedPinID)
{
	DIO_PinValue(LedPortID,LedPinID,HIGH);
}

void LED_off(u8 LedPortID,u8 LedPinID)
{
	DIO_PinValue(LedPortID,LedPinID,LOW);
}

void LED_toggle(u8 LedPortID,u8 LedPinID)
{
	DIO_TOGGLE_PIN(LedPortID,LedPinID);
}