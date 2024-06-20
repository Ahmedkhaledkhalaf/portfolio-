/*
 * EEPROM_cnfig.h
 *
 * Created: 12/16/2022 10:19:17 PM
 *  Author: Eng Ahmed khaled
 */ 


#ifndef EEPROM_CNFIG_H_
#define EEPROM_CNFIG_H_
#include "I2C_config.h"

#define  EEPROM_FIXED_ADDRESS  0x50
void EEPROM_WriteByte(u16 ByteAddress, u8 DATA);
void EEPROM_ReadByte(u16 ByteAddress, u8* DATA);

#endif /* EEPROM_CNFIG_H_ */