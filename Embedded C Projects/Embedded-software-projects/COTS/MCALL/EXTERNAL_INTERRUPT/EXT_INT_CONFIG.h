/*
 * Interrupt.h
 *
 * Created: 11/5/2022 9:34:27 PM
 *  Author: Eng Ahmed khaled
 */ 
#include "DATA_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGS.h"

//Header guard
#ifndef EXT_INT_CONFIG_H
#define EXT_INT_CONFIG_H

//Enum for Interrupt Source pins
typedef enum {EXTI_INT0, EXTI_INT1, EXTI_INT2} EXTI_SOURCE_t;

//Enum for interrupt Trigger edge
typedef enum {EXTI_RISING_EDGE, EXTI_FALLING_EDGE, EXTI_LOW_LEVEL, EXTI_ANY_LOGICAL_CHANGE} EXTI_TRIGGER_t;

//Prototypes for interrupt functions
void EXTI_enable(EXTI_SOURCE_t InterruptSource, EXTI_TRIGGER_t InterruptTrigger); //External interrupt enabling function

void EXTI_diasble(EXTI_SOURCE_t InterruptSource); //External interrupt disabling function

#endif /*EXT_INT_CONFIG_H*/