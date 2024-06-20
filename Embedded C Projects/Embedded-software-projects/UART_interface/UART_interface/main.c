/*
 * UART_interface.c
 *
 * Created: 12/10/2022 7:12:07 PM
 * Author : Eng Ahmed khaled
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include "UART_config.h"
#include "DIO_CONFIG.h"


int main(void)
{
			DIO_SetPinDirection(DIO_PORTD, PIN1, DIO_PIN_OUTPUT); //Tx
			DIO_SetPinDirection(DIO_PORTD, PIN0, DIO_PIN_INPUT); //Rx
			
			UART_init();
    /* Replace with your application code */
    while (1) 
    {
		UART_TxChar('H');
		_delay_ms(1000);
    }
}

