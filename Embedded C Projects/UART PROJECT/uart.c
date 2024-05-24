/**
 * @file uart.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "uart.h"


void UART_Send_string (unsigned char *P_tx_String)
{
    while (*P_tx_String != '\0')
    {
        UART0DR = (unsigned int)(*P_tx_String);
        P_tx_String++;
    }
    
}