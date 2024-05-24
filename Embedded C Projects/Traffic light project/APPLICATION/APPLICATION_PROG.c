/*
 * APPLICATION_PROG.c
 *
 * Created: 11/9/2022 8:21:30 PM
 *  Author: Eng Ahmed khaled
 */ 
#include "APPLICATION_Config.h"


// count variable keeps track of program during execution from phase_1 (0) to phase_4 (3). Initially at phase_1 (0)
u8 count = phase_1;

// first_click flag holds the value (0) when in normal mode. Once it is clicked its value turns to (1) indicating pedestrian mode.
u8 first_click = 0;

u8 ovf;
u8 count;
u8 first_click;
/** This is the app initialization in which all the system drivers are set up **/

void APP_Init(void)
{
	
	//Car LED initialization
	LED_init(CARS_LED_PORT, CARS_LED_R_PIN);
	LED_init(CARS_LED_PORT, CARS_LED_Y_PIN);
	LED_init(CARS_LED_PORT, CARS_LED_G_PIN);
	
	//Pedestrian LED initialization
	LED_init(PED_LED_PORT, PED_LED_R_PIN);
	LED_init(PED_LED_PORT, PED_LED_Y_PIN);
	LED_init(PED_LED_PORT, PED_LED_G_PIN);
	
	//Button initialization
	BUTTON_init(BUTTON_PORT,BUTTON_PIN);
	
	//Timer initialization
	TIMER_0_init();
	// Enabling Timer_0 overflow interrupt
	INTERRUPT_T0_ovf_init();
	//Enable Global interrupts & setup rising edge detection for button
	sei();
	EXTI_enable(EXTI_INT0, EXTI_RISING_EDGE);
	
}
void APP_Start(void)
{
	
	//************************************* Phase 1 *************************************//
	
	if(count == phase_1)
	{
		// Initial start of the normal mode cycle
		LED_on(CARS_LED_PORT, CARS_LED_G_PIN);
		LED_on(PED_LED_PORT, PED_LED_R_PIN);
		
		// This function start a 5 seconds delay
		TIMER_0_delay();
	
		// count is incremented by one to go to next phase, then modulus 4 to make the range of values (0-3) --> (phase_1 - phase_4)
		count = (count+1) % 4;
	}
	
	//***********************************************************************************//
	
	
	
	//************************************* Phase 2 *************************************//
	if(count == phase_2)
	{
		/*	In this phase, timer_0 overflow interrupt blinks cars yellow light in normal mode
			and both cars and pedestrian yellow light in pedestrian mode. */
		TIMER_0_delay();
		
		// Turning both yellow leds off to ensure toggling ends with an off states for the leds after blinking.
		LED_off(CARS_LED_PORT, CARS_LED_Y_PIN);
		LED_off(PED_LED_PORT, PED_LED_Y_PIN);
		
		count = (count+1) % 4;
	}
	
	//***********************************************************************************//
	
	
	
	//************************************* Phase 3 *************************************//
	if(count == phase_3)
	{
		// Program only enters this if condition in pedestrian mode (first_click==1)
		if(first_click)
		{
			// Allowing pedestrians to cross the road by turning on green light and turning off red light in pedestrian mode.
			LED_on(PED_LED_PORT, PED_LED_G_PIN);
			LED_off(PED_LED_PORT, PED_LED_R_PIN);
		}
		
		// Stopping the cars in normal mode by turning on red light and turning off green light.
		LED_off(CARS_LED_PORT, CARS_LED_G_PIN);
		LED_on(CARS_LED_PORT, CARS_LED_R_PIN);
		
		TIMER_0_delay();
		
		count = (count+1) % 4;
	}
	//***********************************************************************************//
	
	
	
	//************************************* Phase 4 *************************************//
	
	/*	In this phase, timer_0 overflow interrupt blinks cars yellow light in normal mode
		and both cars and pedestrian yellow light in pedestrian mode. */
	TIMER_0_delay();
	
	// Turning off pedestrian green light in case of pedestrian mode to exit and enter normal mode phase_1 again.
	LED_off(PED_LED_PORT, PED_LED_G_PIN);
	
	// Turning off cars blinking yellow light in case of normal mode to start again from phase_1.
	LED_off(CARS_LED_PORT, CARS_LED_Y_PIN);
	
	// Turning off pedestrian yellow light in case of pedestrian mode to exit and enter normal mode phase_1 again.
	LED_off(PED_LED_PORT, PED_LED_Y_PIN);
	
	
	if(count == phase_4)
	{
		count = (count+1) % 4;
		
		// Turning off cars blinking red light in case of normal mode to start again from phase_1.
		LED_off(CARS_LED_PORT, CARS_LED_R_PIN);
		
		// Setting first_click flag to zero to indicate returning to normal mode.
		first_click = 0;
	}
	//***********************************************************************************//
	//***********************************************************************************//
	
}

ISR(EXT_INT_0)
{
	
	
	// If the first_click flag is true (clicked) then the button interrupt won't do anything. Thus, eliminating double-click effect.
	// Interrupt 0 triggers on rising edge so the long press will make the same effect as normal press.
	
	if(!first_click)
	{
		
		// if pressed in phase_1 it skips green light remaining wait time and turns on car blinking yellow light, while cars green light is still on.
	    if(count == phase_1)
		{
			ovf = 20;
		}
		
		// if pressed in phase_2 it resets cars blinking yellow light remaining wait time and turns on pedestrians blinking yellow light.
		 if(count == phase_2)
		{
			
			// For syncing the two yellow leds
			LED_off(CARS_LED_PORT, CARS_LED_Y_PIN);
			LED_off(PED_LED_PORT, PED_LED_Y_PIN);
			
			TIMER_0_reset();
		}
		
		// if pressed in phase_3 it resets cars red light remaining wait time, turns pedestrians green light on and red light off.
		else if(count == phase_3)
		{
			TIMER_0_reset();
			LED_off(PED_LED_PORT, PED_LED_R_PIN);
			LED_on(PED_LED_PORT, PED_LED_G_PIN);
		}
		
		// if pressed in phase_4 it skips cars blinking yellow light remaining wait time and go back to phase_2.
		// turning back the count variable to phase_2 reverses the flow of the cars light from (yellow to green) to (yellow to red) again.
		else if(count == phase_4)
		{
			ovf=20;
			count = phase_2;
		}
		
		// Setting first_click variable to (1) indicates pedestrian mode. It is set back to (0) when the 4 phases are complete.
		first_click = 1;
	}
}


// Timer_0 overflow interrupt
ISR(TIMER_0_OVF)
{
	// Resetting initial value for the next timer cycle
	TIMER_0_set_init_value(init_value);
	
	// Incrementing overflow variable
	ovf++;
	
	// Blinking yellow lights only in phase_2 and phase_4
	if(count== phase_2 || count == phase_4)
	{
		// Only blink cars yellow light in normal mode
		if(!first_click)
		{
			LED_toggle(CARS_LED_PORT, CARS_LED_Y_PIN);
		}
		// Blink both yellow lights in pedestrian mode
		else if(first_click)
		{
			LED_toggle(CARS_LED_PORT, CARS_LED_Y_PIN);
			LED_toggle(PED_LED_PORT,  PED_LED_Y_PIN);
		}
	}
}

