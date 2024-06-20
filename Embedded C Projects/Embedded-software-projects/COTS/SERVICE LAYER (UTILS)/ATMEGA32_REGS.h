/**
 * @file AVR_REGS.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 1.5
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

/* watchdog timer */

#define WDTCR                           (* (volatile u8*) 0x41)   


/* UART regs */

//USART control and status register A

#define UCSRA                      (* (volatile u8*) 0x2B)

//USART control and status register B
#define UCSRB         			   (* (volatile u8*) 0x2A)

//USART control and status register C
#define UCSRC                      (* (volatile u8*) 0x40)

//USART baud rate registers
#define	UBRRL   				   (* (volatile u8*) 0x29)
#define UBRRH					   (* (volatile u8*) 0x40)
#define  UDR                       (* (volatile u8*) 0x2C)



                       /* SPI REGISTERS*/
						 
// SPI Control Register
#define SPCR     (*(volatile u8*)0x2D) 

// SPI Status Register
#define SPSR     (*(volatile u8*)0x2E) 

// SPI Data Register
#define SPDR     (*(volatile u8*)0x2F) 



/*Text replacement and naming*/
#define HIGH 1					   
#define LOW  0

#define DIO_PIN_OUTPUT          1  
#define DIO_PIN_INPUT           0

#define DIO_PORTA        0		   
#define DIO_PORTB        1
#define DIO_PORTC        2
#define DIO_PORTD        3
#define NULL             0x0
//

enum PINS {PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7};

#endif /*ATMEGA32_REGS_H*/



/*

/*
 * ATMEGA32_REG.h
 *
 * Created: 10/22/2022 11:12:21 PM
 *  Author: AMIT
 */ 

/*
#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_


                                  /* DIO REGISTERS*/
/* DATA DIRCTION REGISTERS */
/*
#define DDRA   (*(volatile u8*)0x3A)
#define DDRB   (*(volatile u8*)0x37)
#define DDRC   (*(volatile u8*)0x34)
#define DDRD   (*(volatile u8*)0x31)


/* PORT REGISTERS */
/*
#define PORTA  (*(volatile u8*)0x3B)
#define PORTB  (*(volatile u8*)0x38)
#define PORTC  (*(volatile u8*)0x35)
#define PORTD  (*(volatile u8*)0x32)


/* PIN REGISTERS */
/*
#define PINA   (*(volatile u8*)0x39)
#define PINB   (*(volatile u8*)0x36)
#define PINC   (*(volatile u8*)0x33)
#define PIND   (*(volatile u8*)0x30)


                           /* EXTERNAL INTERRUPT REGISTERS*/
	
// MCU Control Register	
/*
#define MCUCR    (*(volatile u8*)0x55)	

// MCU Control and Status Register						   
#define MCUCSR   (*(volatile u8*)0x54)

// General Interrupt Control Register	
#define GICR     (*(volatile u8*)0x5B)

// General Interrupt Flag Register	
#define GIFR     (*(volatile u8*)0x5A)

// Status Register	
#define SREG     (*(volatile u8*)0x5F)


                                      /* ADC REGISTERS*/
/*									  
// ADC Multiplexer Selection Register	
#define ADMUX    (*(volatile u8*)0x27)	

// ADC Control and Status Register A	
#define ADCSRA   (*(volatile u8*)0x26)

// The ADC Data Registers	
#define ADCL     (*(volatile u8*)0x24)
#define ADCH     (*(volatile u8*)0x25)
#define ADC_u16  (*(volatile u16*)0x24)

// Special FunctionIO Register	
#define SFIOR    (*(volatile u8*)0x50)

          
		                        /* TIMERS REGISTERS*/
	/*
// Timer/Counter Interrupt Mask Register
#define TIMSK          (*(volatile u8*)0x59)

// Timer/Counter Interrupt Flag Register
#define TIFR           (*(volatile u8*)0x58)


/* TIMER0 */
/*
// Timer/Counter Control Register
#define TCCR0          (*(volatile u8*)0x53)

// Timer/Counter Register
#define TCNT0          (*(volatile u8*)0x52)

// Output Compare Register
#define OCR0           (*(volatile u8*)0x5C)



/* TIMER1 */
// Timer/Counter1 Control Register A
/*
#define TCCR1A     (*(volatile u8*)0x4F)

// Timer/Counter1 Control Register B
#define TCCR1B     (*(volatile u8*)0x4E)

// Timer/Counter1
#define TCNT1_u16  (*(volatile u16*)0x4C)

// Output Compare Register 1A
#define OCR1A_u16  (*(volatile u16*)0x4A)

// Output Compare Register 1B
#define OCR1B_u16  (*(volatile u16*)0x48)

// Input Capture Register 1
#define ICR1_u16   (*(volatile u16*)0x46)


/* WDT */
/*
//Watchdog Timer Control Register
#define WDTCR      (*(volatile u8*)0x41)

                             /* UART REGISTERS*/
							 
// USART I/O Data Register
/*
#define UDR       (*(volatile u8*)0x2C) 

// USART Control and Status Register A
#define UCSRA     (*(volatile u8*)0x2B) 	

// USART Control and Status Register B
#define UCSRB     (*(volatile u8*)0x2A) 

// USART Control and Status Register C
#define UCSRC     (*(volatile u8*)0x40) 

// USART Baud Rate Registers
#define UBRRL     (*(volatile u8*)0x29) 
#define UBRRH     (*(volatile u8*)0x40) 


                             /* SPI REGISTERS*/
					/*		 
// SPI Control Register
#define SPCR     (*(volatile u8*)0x2D) 

// SPI Status Register
#define SPSR     (*(volatile u8*)0x2E) 

// SPI Data Register
#define SPDR     (*(volatile u8*)0x2F) 

#endif /* ATMEGA32_REG_H_ */

