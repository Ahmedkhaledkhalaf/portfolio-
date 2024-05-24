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


#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H

//including libraries 
#include "../../SERVICE (UTILS)/DATA_TYPES.h"
#include "../../SERVICE (UTILS)/ATMEGA32_REGS.h"
#include "../../SERVICE (UTILS)/BIT_MATH.h"



/*prototypes of the functions*/

void DIO_SetPinDirection(u8 PortId, u8 PinID, u8 PinDirection);
void DIO_PinValue(u8 PortId, u8 PinID, u8 PinValue);
u8 DIO_GET_PIN_VALUE(u8 PortId, u8 PinID);
void DIO_TOGGLE_PIN(u8 PortId, u8 PinID);
void DIO_ActevatePullUp(u8 PortId, u8 PinID);


#endif /*DIO_CONFIG_H header guard*/