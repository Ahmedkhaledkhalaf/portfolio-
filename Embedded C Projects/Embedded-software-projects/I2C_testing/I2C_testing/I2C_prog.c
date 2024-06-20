/*
 * I2C_prog.c
 *
 * Created: 12/16/2022 6:56:39 PM
 *  Author: Eng Ahmed khaled
 */ 


/*utiles */
#include "BIT_MATH.h"
#include "ATMEGA32_REGS.h"



/* MCAL */
#include "I2C_config.h"


void TWI_InitMaster(void)

{
	
	// Set Prescaller = 1 >> Set Freq = 400 KHZ
	
	
	RESET(TWSR, 0);
	RESET(TWSR, 1);
	TWBR = 12;
	SET(TWCR, 6); // Acknowledge ENABLE
	SET(TWCR, 2); //ENABLE peripheral
	
}


void TWI_SEND_StartCond(void)

{
	
	SET(TWCR, 5); //when this bit is set to 1 the master will send a start cond. 
	
	// Clear the flag to start the job
	SET(TWCR, 7);
	
	
	// wait for the flag to check whether the start cond is sent successfully or not

	while(0 == GET_BIT(TWCR,7));
	//check ACK == Start Cond. ACK
	while((TWSR & 0xF8) != 0x08);
}


void TWI_SENDREPEATED_StartCond(void)
{
	SET(TWCR, 5); //when this bit is set to 1 the master will send a start cond.
	
	// Clear the flag to start the job
	SET(TWCR, 7);
	// wait for the flag to check whether the start cond is sent successfully or not
	while(0 == GET_BIT(TWCR,7));
	
	//check ACK == REPEATED Start Cond. ACK
	while((TWSR & 0xF8) != 0x10);
}


void TWI_SEND_StopCond(void)

{
	// Send Stop cod
	SET(TWCR, 4);
	
	// Clear the flag to start the job
	SET(TWCR, 7);
}

void TWI_SendSlaveAddWithWrite(u8 SlaveADD)
{
		if (SlaveADD < 128)
		{
			
			// Select slave address
			// PUT the ADD at the MSB
			TWDR = (SlaveADD >> 1);
			// Select Write operation
			RESET (TWDR, 0);
			
			//Clear SC Bit
			RESET(TWCR, 5);
				// Clear the flag to start the job
			SET(TWCR, 7);
			
			// wait for the flag to check whether the start cond is sent successfully or not
			while(0 == GET_BIT(TWCR,7));
			
			//check ACK == Master transmit (Slave add + Write requist) ACK
			while((TWSR & 0xF8) != 0x18);
		}
}



void TWI_SendSlaveAddWithRead(u8 SlaveADD)
{
	if (SlaveADD < 128)
	{
		// Select slave address
		// PUT the ADD at the MSB
		TWDR = (SlaveADD << 1);
		// Select Read operation
		SET(TWDR, 0);
		//Clear SC Bit
		RESET(TWCR, 5);
		// Clear the flag to start the job
		SET(TWCR, 7);
		
		// wait for the flag to check whether the start cond is sent successfully or not
		while(0 == GET_BIT(TWCR,7));
		
		//check ACK == Master transmit (Slave add + Write requist) ACK
		while((TWSR & 0xF8) != 0x40);
	}
}
void TWI_SendMasterByteDATA(u8 DATA)

{
	// Write Data into the REGISTER
	TWDR = DATA;
	
	// Clear the flag to start the job
	SET(TWCR, 7);
	
	
	// wait for the flag to check whether the start cond is sent successfully or not
	while(0 == GET_BIT(TWCR,7));
	
	
	//check ACK == Master transmit (Slave add + Write requist) ACK
	while((TWSR & 0xF8) != 0x28);
}



void TWI_ReciveMasterByteDATA(u8* RetDATA)
{
	
	
	if (RetDATA != NULL)
	{
		// Clear the flag to start the job
		SET(TWCR, 7);
		
		
		// wait for the flag to check whether the start cond is sent successfully or not
		while(0 == GET_BIT(TWCR,7));
		
		
		//check ACK == Master transmit (Slave add + Write requist) ACK
		while((TWSR & 0xF8) != 0x50);
		
		// DAta reading
			*RetDATA = TWDR;
	}
}
