/**
 * @file DIO_CONFIG.h
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "DATA_TYPES.h"
#include "ATMEGA32_REGS.h"
/*prototypes of the functions*/

#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H
void DIO_SetPinDirection(u8 PortId, u8 PinID, u8 PinDirection);
void DIO_PinValue(u8 PortId, u8 PinID, u8 PinValue);
u8 DIO_GET_PIN_VALUE(u8 PortId, u8 PinID);
void DIO_TOGGLE_PIN(u8 PortId, u8 PinID);
void DIO_ActevatePullUp(u8 PortId, u8 PinID);
#endif /*DIO_CONFIG_H header guard*/