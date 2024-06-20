/*
 * SPI_interface.h
 *
 * Created: 12/13/2022 7:21:19 PM
 *  Author: AMIT
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_initMaster(void);
void SPI_initSlave (void);
void SPI_SlaveInit (void)
char SPI_SlaveReceive(void)
void SPI_transieve (u8 TxData,u8* RxData);


#endif /* SPI_INTERFACE_H_ */