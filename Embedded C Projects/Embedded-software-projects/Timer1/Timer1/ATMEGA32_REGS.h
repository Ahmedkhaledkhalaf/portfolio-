/**
 * @file AVR_REGS.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "DATA_TYPES.h"

#ifndef ATMEGA32_REGS_H
#define ATMEGA32_REGS_H


/*memory mapping for Data Direction registers*/
#define DDRA                            (* (volatile u8*) 0x3A)
#define DDRB                            (* (volatile u8*) 0x37)
#define DDRC                            (* (volatile u8*) 0x34)
#define DDRD                            (* (volatile u8*) 0x31)



/*memory mapping for output registers*/
#define PORTA                           (* (volatile u8*) 0x3B)
#define PORTB                           (* (volatile u8*) 0x38)
#define PORTC                           (* (volatile u8*) 0x35)
#define PORTD                           (* (volatile u8*) 0x32)


/*memory mapping for input registers*/
#define PINA                            (* (volatile u8*) 0x39)
#define PINB                            (* (volatile u8*) 0x36)
#define PINC                            (* (volatile u8*) 0x33)
#define PIND                            (* (volatile u8*) 0x30)

// External Interrupt registers

#define MCUCR                           (* (volatile u8*) 0x55)
#define MCUCSR                          (* (volatile u8*) 0x54)
#define GICR                            (* (volatile u8*) 0x5B)
#define GIFR                            (* (volatile u8*) 0x5A)
#define SREG                            (* (volatile u8*) 0x5F)

/* Timer 0 regs */


#define TCCR0                           (* (volatile u8*) 0x53)
#define TCNT0                           (* (volatile u8*) 0x52)
#define OCR0                            (* (volatile u8*) 0x5C)

/* Timers interrupt regs */

#define TIMSK                           (* (volatile u8*) 0x59)
#define TIFR                            (* (volatile u8*) 0x58)


/* Timer 1 regs */



#define TCCR1A                          (* (volatile u8*) 0x4F)
#define TCCR1B							(* (volatile u8*) 0x4E)

/* Timer/Counter1  */
#define TCNT1_U16						(* (volatile u16*) 0x4C)

/* output Compare Register 1A */ 
#define OCR1A_U16						(* (volatile u16*) 0x4A)

/* output Compare Register 1B */ 
#define OCR1B_U16						(* (volatile u16*) 0x48)

/* Input capture register 1 */
#define ICR1_U16     					(* (volatile u16*) 0x46)






/*Text replacement and naming*/
#define HIGH 1
#define LOW  0

#define DIO_PIN_OUTPUT          1
#define DIO_PIN_INPUT           0

#define DIO_PORTA        0
#define DIO_PORTB        1
#define DIO_PORTC        2
#define DIO_PORTD        3

//

enum PINS {PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7};

#endif /*ATMEGA32_REGS_H*/