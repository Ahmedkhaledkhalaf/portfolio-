/**
 * @file uart.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef _UART_H
#define _UART_H

#define UART0DR *((volatile unsigned int* const)((unsigned int*)0x101f1000))
void UART_Send_string (unsigned char *P_tx_String);


#endif