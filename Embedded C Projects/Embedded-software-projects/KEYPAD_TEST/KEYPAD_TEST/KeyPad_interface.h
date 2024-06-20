/*
 * KeyPad_interface.h
 *
 * Created: 10/29/2022 11:27:15 PM
 *  Author: Eng Ahmed khaled
 */ 


#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H
#include "DATA_TYPES.h"


#define  KPD_NOT_PRESSED 255

void KPD_InitDirections(void);
void KPD_getvalue(u8* retval);
void KPD_init(void);
#endif /*KEYPAD_INTERFACE_H*/