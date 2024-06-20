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

#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H


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
/*Text replacement and namming*/
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
