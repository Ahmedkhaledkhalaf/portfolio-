/*
 * UART_prog.c
 *
 * Created: 12/10/2022 7:13:01 PM
 *  Author: Eng Ahmed khaled
 */ 
#include "UART_config.h"



// function that initiate the UART
void UART_init(void)
{
	
	// writing the UCSRC , //select UART MODE = Asynchronous , // configure no parity,
	// configure data bits = 8, // configure stop bits = 1
	
	
	UCSRC = 0x86;
	RESET(UCSRB,2);
	
	// set buad rate = 9600
	UBRRL = 103;
	
	//enable Tx
	SET(UCSRB,3);
	//enable Rx
    SET(UCSRB,3);
	
}



//function that transmit data
void UART_TxChar(u8 data)
{
	UDR = data;
	
	while( 0 == GET_BIT(UCSRA, 5));
	
	
}


//function that receive data
void UART_RxChar(u8* retval)
{
	if (retval != NULL)
	{
		
		while(0 == GET_BIT(UCSRA, 7));
		*retval = UDR;
	}
	else
	{
		
		// DO Nothing
	}
	
}
