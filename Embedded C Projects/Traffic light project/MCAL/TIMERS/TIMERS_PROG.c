/*
 * TIMERS_PROG.c
 *
 * Created: 11/9/2022 6:57:33 PM
 *  Author: Eng Ahmed khaled
 */ 

#include "Timers_Config.h"
#include <math.h>

/** After performing timer calculations to make a 5 seconds delay, prescaler 1024 is used, number of overflows is 20, and initial value is 11 **/


// Declaring extern variables to be accessed by timer driver
extern u8 count;
extern u8 first_click;

// Overflow counter for timer_0
u8 ovf;


void TIMER_0_init()
{
	//selecting normal mode
	TCCR0 |= ((0<<3) | (0<<6));
	
	TIMER_0_set_init_value(init_value);
}

void TIMER_0_set_init_value(u8 val)
{
	//assigning initial value after calculation
	TCNT0 = val;
}

void TIMER_0_start()
{
	// Selecting 1024 prescaler
	TCCR0 |= ((1<<0) | (1<<2));
	
	// Waiting the overflow counter to reach 20
	while(ovf <20);
}


void TIMER_0_stop()
{
	// Setting control register to 0 (no prescaler) to stop the timer
	TCCR0 = 0x00;
	
	// Resetting overflow counter
	ovf = 0;
}

// Delay function that perform the 5 seconds delay
void TIMER_0_delay()
{
	TIMER_0_start();
	TIMER_0_stop();
}

// This function resets timer without stopping it
void TIMER_0_reset()
{
	TIMER_0_set_init_value(init_value);
	ovf = 0;
}

void INTERRUPT_T0_ovf_init()
{
	//enabling t0_ovf interrupt
	SET(TIMSK, 0);
}


