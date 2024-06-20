/*
 * UART_config.h
 *
 * Created: 12/10/2022 7:13:22 PM
 *  Author: Eng Ahmed khaled
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#include "DATA_TYPES.h"
#include "ATMEGA32_REGS.h"
#include "BIT_MATH.h"
void UART_init(void);
void UART_TxChar(u8 data);
void UART_RxChar(u8* retval);



#endif /* UART_CONFIG_H_ */