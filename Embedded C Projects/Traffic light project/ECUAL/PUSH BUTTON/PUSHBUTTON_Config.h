/*
 * PUSHBUTTON_Config.h
 *
 * Created: 11/9/2022 8:09:28 PM
 *  Author: Eng Ahmed khaled
 */ 


#ifndef PUSHBUTTON_CONFIG_H_
#define PUSHBUTTON_CONFIG_H_

#include "../../MCAL/DIO/DIO_CONFIG.h"
#include "../MCAL/EXT_INTERRUPT/EXT_INT_CONFIG.h"
//Button port and pin
#define BUTTON_PORT            DIO_PORTD
#define BUTTON_PIN             PIN2


//initialize
void BUTTON_init(u8 ButtonPortID, u8 ButtonPinID);

// button read
//void BUTTON_read(u8 ButtonPortID, u8 ButtonPinID, u8* ButtonVal);



#endif /* PUSHBUTTON_CONFIG_H_ */