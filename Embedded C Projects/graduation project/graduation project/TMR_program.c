/*
 * TMR_program.c
 *
 * Created: 11/12/2022 10:15:26 PM
 *  Author: AMIT
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "TMR_interface.h"
#include "TMR_config.h"


/* TIMER0 */

static void(*timer0_ctc_pCallBack)(void)=NULL;

void TMR_timer0Init(void)
{
#if TMR_TIMER0_MODE == TMR_TIMER0_NORMAL_MODE
	// Select Mode = Normal Mode
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	
	// Init Timer With Preload Value
	TCNT0 = TMR_TIMER0_PRELOAD_VALUE;
	
	// Enable OVF Interrupt
	SET_BIT(TIMSK,0);
#elif TMR_TIMER0_MODE == TMR_TIMER0_CTC_MODE
    // Select Mode = CTC Mode
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	
	// Enable CTC Interrupt
	SET_BIT(TIMSK,1);
#elif TMR_TIMER0_MODE == TMR_TIMER0_FAST_PWM_MODE
    //set OC0 as output pin
	SET_BIT(DDRB,3);
	
    // Select Mode = FAST PWM Mode
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	
	// Select Non Inverting Mode
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#endif

	// Select Prescaler Value = 64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}


void TMR_timer0setCompareMatchValue(u8 compareValue)
{
	// Init Timer With Compare Value
	OCR0 = compareValue;
}


void TMR_timer0_CTC_SetCallBack(void(*ptr)(void))
{
	timer0_ctc_pCallBack = ptr;
}


// ISR Function protoType for TOV0
void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)
{
	static u16 counterOVF = 0;
	counterOVF++;
	
	if(counterOVF == TMR_TIMER0_OVERFLOW_COUNTER)
	{
		// Set Preload Value
		TCNT0 = TMR_TIMER0_PRELOAD_VALUE;
		
		// Clear Counter
		counterOVF = 0;
		
		//call action
		
	}
}


// ISR Function protoType for CTC0
void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
	static u16 counterCTC = 0;
	counterCTC++;
	
	if(counterCTC == TMR_TIMER0_CTC_COUNTER)
	{
		// Clear Counter
		counterCTC = 0;
		
		// Call Action
		timer0_ctc_pCallBack();
	}
}


/* TIMER1 */
void TMR_timer1Init(void)
{
	//set OC1A as output pin
	SET_BIT(DDRD,5);
	
	// Select Mode = Fast PWM Mode(14)
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	
	// Select Non Inverting Mode
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
	
	// ICR1 >> period time = 20ms >> freq. = 50HZ
	ICR1_u16 = 4999;
	
	// Select Prescaler Value = 64
	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}


void TMR_timer1setCompareMatchAValue(u16 compareValue)
{
	// Init Timer With Compare Value
	OCR1A_u16 = compareValue;
}