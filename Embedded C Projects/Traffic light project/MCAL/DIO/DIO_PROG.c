/**
 * @file DIO_PROG.c
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include "DIO_CONFIG.h"



void DIO_SetPinDirection(u8 PortId, u8 PinID, u8 PinDirection)
{
    switch (PortId)
    {
    case DIO_PORTA:
      if (PinDirection == DIO_PIN_OUTPUT)
      {
         SET(DDRA, PinID);
      }
      else
      {
         RESET(DDRA, PinID);
      }
      break;
   case DIO_PORTB:
      if (PinDirection == DIO_PIN_OUTPUT)
      {
         SET(DDRB, PinID);
      }
      else
      {
         RESET(DDRB, PinID);
      }
      break;
   
   case DIO_PORTC:
      if (PinDirection == DIO_PIN_OUTPUT)
      {
         SET(DDRC, PinID);
      }
      else
      {
         RESET(DDRC, PinID);
      }
      break;
   
   case DIO_PORTD:
      if (PinDirection == DIO_PIN_OUTPUT)
      {
         SET(DDRD, PinID);
      }
      else
      {
         RESET(DDRD, PinID);
      }
      break;

    }
     
}

void DIO_PinValue(u8 PortId, u8 PinID, u8 PinValue)
{
     switch (PortId)
    {
    case DIO_PORTA:
      if (PinValue == HIGH)
      {
         SET(PORTA, PinID);
      }
      else
      {
         RESET(PORTA, PinID);
      }
      break;
   case DIO_PORTB:
      if (PinValue == HIGH)
      {
         SET(PORTB, PinID);
      }
      else
      {
         RESET(PORTB, PinID);
      }
      break;
   
   case DIO_PORTC:
      if (PinValue == HIGH)
      {
         SET(PORTC, PinID);
      }
      else
      {
         RESET(PORTC, PinID);
      }
      break;
   
   case DIO_PORTD:
      if (PinValue == HIGH)
      {
         SET(PORTD, PinID);
      }
      else
      {
         RESET(PORTD, PinID);
      }
      break;
}
}

u8 DIO_GET_PIN_VALUE(u8 PortId, u8 PinID)
{
   u8 PIN_state = 0;

   switch (PortId)
    {
    case DIO_PORTA:
      if (GET_BIT(PINA, PinID) == HIGH)
      {
         PIN_state = HIGH;
      }

      else
      {
         PIN_state = LOW;
      }
       
      break;
   case DIO_PORTB:
      if (GET_BIT(PINB, PinID) == HIGH)
      {
         PIN_state = HIGH;
      }

      else
      {
         PIN_state = LOW;
      }
       
      break;
   
   case DIO_PORTC:
      if (GET_BIT(PINC, PinID) == HIGH)
      {
         PIN_state = HIGH;
      }

      else
      {
         PIN_state = LOW;
      }
       
      break;
   
   case DIO_PORTD:
      if (GET_BIT(PIND, PinID) == HIGH)
      {
         PIN_state = HIGH;
      }

      else
      {
         PIN_state = LOW;
      }
       
      break;

}
   return PIN_state;

}

void DIO_TOGGLE_PIN(u8 PortId, u8 PinID)
{
    switch (PortId)
    {
    case DIO_PORTA:
      TOGGLE(PORTA, PinID);
      break;
   case DIO_PORTB:
      TOGGLE(PORTB, PinID);
      break;
   
   case DIO_PORTC:
      TOGGLE(PORTC, PinID);
      break;
   
   case DIO_PORTD:
      TOGGLE(PORTD, PinID);
      break;
}
}

void DIO_ActevatePullUp(u8 PortId, u8 PinId)
{
 switch (PortId)
	 {
		 case DIO_PORTA:
		     SET(PORTA, PinId);
		     break;			
		 case DIO_PORTB:	
	         SET(PORTB, PinId);
		     break;			
		 					
		 case DIO_PORTC:	
		     SET(PORTC, PinId);
		     break;
		 
		 case DIO_PORTD:
		      SET(PORTD, PinId);
			  break;

	 }
}