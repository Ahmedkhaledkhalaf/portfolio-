/*
 * Interrupt.c
 *
 * Created: 11/5/2022 9:34:49 PM
 *  Author: Eng Ahmed khaled
 */ 
#include "EXT_INT_CONFIG.h"


void EXTI_enable(EXTI_SOURCE_t InterruptSource, EXTI_TRIGGER_t InterruptTrigger) //External interrupt enabling function

{
	switch(InterruptSource)
	{
		case EXTI_INT0:
		   switch(InterruptTrigger)
		   {
		       case EXTI_RISING_EDGE:
			     RESET(MCUCSR, 2);
				 SET(MCUCSR, 3);
				 break;
				 
			   case EXTI_FALLING_EDGE:
			     SET(MCUCSR, 2);
			     SET(MCUCSR, 3);
			     break;
			   
			   case EXTI_LOW_LEVEL:
			     RESET(MCUCSR, 2);
			     RESET(MCUCSR, 3);
			     break;
			   
			   case EXTI_ANY_LOGICAL_CHANGE:
			     SET(MCUCSR, 2);
			     RESET(MCUCSR, 3);
			     break;
		   }
		   SET(GICR, 6);
		   break;
		   
		case EXTI_INT1:
		 switch(InterruptTrigger)
		 {
			 case EXTI_RISING_EDGE:
			 RESET(MCUCSR, 0);
			 SET(MCUCSR, 1);
			 break;
			 
			 case EXTI_FALLING_EDGE:
			 SET(MCUCSR, 0);
			 SET(MCUCSR, 1);
			 break;
			 
			 case EXTI_LOW_LEVEL:
			 RESET(MCUCSR, 0);
			 RESET(MCUCSR, 1);
			 break;
			 
			 case EXTI_ANY_LOGICAL_CHANGE:
			 SET(MCUCSR, 0);
			 RESET(MCUCSR, 1);
			 break;
		 }
		   SET(GICR, 7);
		   break;
		
		case EXTI_INT2:
		  switch (InterruptTrigger)
		   {
			 case EXTI_RISING_EDGE:
			      SET(MCUCSR, 6);
			      break;
			 
			 case EXTI_FALLING_EDGE:
			      RESET(MCUCSR, 6);
			      break;
				  
			 case EXTI_LOW_LEVEL:
			      break;
			 
			 case EXTI_ANY_LOGICAL_CHANGE:
			      break;
			 
		   }
		   SET(GICR, 5);
		   break;
	}
	
}
void EXTI_diasble(EXTI_SOURCE_t InterruptSource) //External interrupt disabling function

{
	switch(InterruptSource)
	{
		case EXTI_INT0:
		   RESET(GICR, 6);
		   break;
		   
		case EXTI_INT1:
		   RESET(GICR, 7);
		   break;
		   
		case EXTI_INT2:
		  RESET(GICR, 5);
		  break;
		  
	}
}