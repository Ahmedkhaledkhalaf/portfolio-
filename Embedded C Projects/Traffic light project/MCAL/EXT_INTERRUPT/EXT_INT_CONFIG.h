/*
 * Interrupt.h
 *
 * Created: 11/5/2022 9:34:27 PM
 *  Author: Eng Ahmed khaled
 */ 


//Header guard
#ifndef EXT_INT_CONFIG_H
#define EXT_INT_CONFIG_H


//including libraries
#include "../../SERVICE (UTILS)/DATA_TYPES.h"
#include "../../SERVICE (UTILS)/ATMEGA32_REGS.h"
#include "../../SERVICE (UTILS)/BIT_MATH.h"


//Interrupt vectors
#define EXT_INT_0                __vector_1
#define EXT_INT_1                __vector_2

#define TIMER_0_OVF              __vector_11
//Enable interrupts
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")

//ISR macro
#define ISR(INT_VECT) \
void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)


//Enum for Interrupt Source pins
typedef enum {EXTI_INT0, EXTI_INT1, EXTI_INT2} EXTI_SOURCE_t;

//Enum for interrupt Trigger edge
typedef enum {EXTI_RISING_EDGE, EXTI_FALLING_EDGE, EXTI_LOW_LEVEL, EXTI_ANY_LOGICAL_CHANGE} EXTI_TRIGGER_t;

//Prototypes for interrupt functions
void EXTI_enable(EXTI_SOURCE_t InterruptSource, EXTI_TRIGGER_t InterruptTrigger); //External interrupt enabling function

void EXTI_diasble(EXTI_SOURCE_t InterruptSource); //External interrupt disabling function

void INTERRUPT_T0_ovf_init(void);
#endif /*EXT_INT_CONFIG_H*/