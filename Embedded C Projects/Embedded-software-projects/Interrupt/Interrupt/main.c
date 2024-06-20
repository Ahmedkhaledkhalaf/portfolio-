/*
 * Interrupt.c
 *
 * Created: 11/5/2022 9:19:16 PM
 * Author : Eng Ahmed khaled
 */ 

#define F_CPU 16000000UL
#include "DATA_TYPES.h"
#include "ATMEGA32_REGS.h"
#include "BIT_MATH.h"
#include "DIO_CONFIG.h"
#include "Interrupt.h"
#include <util/delay.h>

int main(void)
{

    /* Replace with your application code */
	DIO_SetPinDirection(DIO_PORTC, PIN2, DIO_PIN_OUTPUT); //LED0
	DIO_SetPinDirection(DIO_PORTD, PIN3, DIO_PIN_OUTPUT); //LED2
	
	SET(SREG, 7); //Enable Global interrupt (SERG the register who has the global interrupt (pin 7))
	EXTI_enable(EXTI_INT0, EXTI_RISING_EDGE);
	
    while (1) 
    {
		_delay_ms(500);
		DIO_TOGGLE_PIN(DIO_PORTD, PIN3);
    }
}

// ISR Function prototype

void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	DIO_TOGGLE_PIN (DIO_PORTC,PIN2);
}