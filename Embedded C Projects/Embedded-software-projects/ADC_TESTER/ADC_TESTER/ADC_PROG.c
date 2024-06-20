/*
 * ADC_PROG.c
 *
 * Created: 11/11/2022 9:47:49 PM
 *  Author: Eng Ahmed khaled
 */ 


//   UTILES
#include "ATMEGA32_REGS.h"
#include "DATA_TYPES.h"
#include "BIT_MATH.h"


//    MCAL

#include "ADC_Config.h"

void ADC_Init(void)
{
	//select Vref As Vcc(5v)
	SET(ADMUX, 6);
	RESET(ADMUX, 7);
	
	//ADJUSTEMENT right
	RESET(ADMUX, 5);
	
	//set single conversion mode
	RESET(ADCSRA, 5);
	
	//set prescaler (division factor) 128
	SET(ADCSRA, 0);
	SET(ADCSRA, 1);
	SET(ADCSRA, 2);
	
	
	
	//Enable ADC
	SET(ADCSRA, 7);
}
void ADC_GetDigitalVal(u16 *RetVal, u8 ChannelNum)
{
	if ((ChannelNum < 32) && (RetVal != NULL))
	{
		//reset channel num
		ADMUX &= 0b11100000;
		//choose channel number
		ADMUX |= ChannelNum;
		
		//start conversion
		SET(ADCSRA, 6);
		
		//wait for the end of conversion
		while(GET_BIT(ADCSRA, 4) == 0);
		
		//clear the flag
		SET(ADCSRA, 4);
		*RetVal = ADCU16;
	}
}
