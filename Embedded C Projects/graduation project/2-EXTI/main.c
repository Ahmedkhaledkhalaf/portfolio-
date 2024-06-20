/*
 * EXTI_test.c
 *
 * Created: 11/5/2022 9:35:40 PM
 * Author : AMIT
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "EXTI_interface.h"
#include "DIO_interface.h"

int main(void)
{
    /* Replace with your application code */
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	
	SET_BIT(SREG,7); //enable global interrupt
	
	EXTI_enable(EXTI_INT0,EXTI_RISING_EDGE);
    while (1) 
    {
    }
}


// ISR Function protoType for EXTI0
void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{
	DIO_togglePinValue(DIO_PORTC,DIO_PIN2);
}



