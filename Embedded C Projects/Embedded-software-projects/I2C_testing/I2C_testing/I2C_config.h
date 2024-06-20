/*
 * I2C_config.h
 *
 * Created: 12/16/2022 6:57:11 PM
 *  Author: Eng Ahmed khaled
 */ 


#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_


#include "DATA_TYPES.h"


void TWI_InitMaster(void);
//void TWI_InitSlave(void);


void TWI_SEND_StartCond(void);
void TWI_SENDREPEATED_StartCond(void);
void TWI_SEND_StopCond(void);

void TWI_SendSlaveAddWithWrite(u8 SlaveADD);
void TWI_SendSlaveAddWithRead(u8 SlaveADD);
void TWI_SendMasterByteDATA(u8 DATA);
void TWI_ReciveMasterByteDATA(u8* RetDATA);



#endif /* I2C_CONFIG_H_ */