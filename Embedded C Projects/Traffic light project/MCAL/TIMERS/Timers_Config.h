/*
 * Timers.h
 *
 * Created: 11/9/2022 6:57:07 PM
 *  Author: Eng Ahmed khaled
 */ 


#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_

//including libraries 
#include "../../SERVICE (UTILS)/DATA_TYPES.h"
#include "../../SERVICE (UTILS)/BIT_MATH.h"
#include "../../SERVICE (UTILS)/ATMEGA32_REGS.h"

//initialization of Timer0
#define init_value 11



// TIMER0 function prototypes
void TIMER_0_init();
void TIMER_0_set_init_value(u8 val);
void TIMER_0_start();
void TIMER_0_stop();
void TIMER_0_reset();

void TIMER_0_delay();








#endif /* TIMERS_CONFIG_H_ */