/*
 * EEPROM_prog.c
 *
 * Created: 12/16/2022 10:18:52 PM
 *  Author: Eng Ahmed khaled
 */ 

#include "DATA_TYPES.h"
#define  F_CPU 16000000UL
#include <util/delay.h>

#include "EEPROM_cnfig.h"


void EEPROM_WriteByte(u16 ByteAddress, u8 DATA)

{
	_delay_ms(5);
	
	u8 Address = (EEPROM_FIXED_ADDRESS | (u8)(ByteAddress >> 8));
	
	//Send SC
	TWI_SEND_StartCond();
	
	//Send Slave Address with write requist
	TWI_SendSlaveAddWithWrite(Address);
	
	//send the remainder of the address as data
	TWI_SendMasterByteDATA((u8)ByteAddress);
	
	//Send Byte Data
	TWI_SendMasterByteDATA(DATA);
	
	//Send Stop Cond
	TWI_SEND_StopCond();
	 
}



void EEPROM_ReadByte(u16 ByteAddress, u8* DATA)
{
	_delay_ms(5);
	
	u8 Address = (EEPROM_FIXED_ADDRESS | (u8)(ByteAddress >> 8));
	
	//Send SC
	TWI_SEND_StartCond();
	
	//Send Slave Address with write requist
	TWI_SendSlaveAddWithWrite(Address);
	
	//send the remainder of the address as data
	TWI_SendMasterByteDATA((u8)ByteAddress);
	
	//Send repeated SC
	TWI_SENDREPEATED_StartCond();
	
	//Send Byte Data
	TWI_SendSlaveAddWithRead(Address);
	
	
	 TWI_ReciveMasterByteDATA(DATA);

	//Send Stop Cond
	TWI_SEND_StopCond();
	
}
