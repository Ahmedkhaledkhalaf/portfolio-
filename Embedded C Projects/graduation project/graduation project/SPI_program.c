/*
 * SPI_program.c
 *
 * Created: 12/13/2022 7:21:05 PM
 *  Author: AMIT
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "SPI_interface.h"


void SPI_initMaster(void)
{
	// init Master Directions
	SET_BIT(DDRB,5);  // MOSI -> OUTPUT
	CLR_BIT(DDRB,6);  // MISO -> INPUT
	SET_BIT(DDRB,7);  // SCLK -> OUTPUT
	SET_BIT(DDRB,4);  // SS   -> OUTPUT
	CLR_BIT(PORTB,4); // SS  -> 0
	
	//select Data Order LSB transmitted first
	SET_BIT(SPCR,5);
	
	// select Master Mode
	SET_BIT(SPCR,4);
	
	// select CLK Polarity Falling => Rising , select CLK Phase Setup => Sample
	SET_BIT(SPCR,3);
	SET_BIT(SPCR,2);
	
	// select CLK Rate = FCPU/16 (1 MHZ)
	SET_BIT(SPCR,0);
	CLR_BIT(SPCR,1);
	CLR_BIT(SPSR,0);
	
	// enable SPI
	SET_BIT(SPCR,6);
}


void SPI_initSlave(void)
{
	// init Slave Directions
	CLR_BIT(DDRB,5); // MOSI -> INPUT
	SET_BIT(DDRB,6); // MISO -> OUTPUT
	CLR_BIT(DDRB,7); // SCLK -> INPUT
	CLR_BIT(DDRB,4); // SS   -> INPUT
	
	
	//select Data Order LSB transmitted first
	SET_BIT(SPCR,5);
	
	// select Slave Mode
	CLR_BIT(SPCR,4);
	
	// select CLK Polarity Falling => Rising , select CLK Phase Setup => Sample
	SET_BIT(SPCR,3);
	SET_BIT(SPCR,2);
	
	// enable SPI
	SET_BIT(SPCR,6);
}


void SPI_transieve(u8 TxData,u8* RxData)
{
	if(RxData != NULL)
	{
		SPDR = TxData;
		
		while(0 == GET_BIT(SPSR,7));
		*RxData = SPDR;
	}
}
char SPI_SlaveReceive(void)
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<7)));
	/* Return data register */
	return SPDR;
}