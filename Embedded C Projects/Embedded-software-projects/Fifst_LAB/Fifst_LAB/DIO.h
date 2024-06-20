#ifndef DIO_H
#define DIO_H

#include "DATA_TYPES.h"

#define NUMBER_OF_PORTS 4

/*define Register addresses from memory map table in the datasheet as a pointer to byte*/
#define PORTA	(u8*)(0X3B)     // PORT register to write the output value
#define DDRA	(u8*)(0X3A)     // DDR register to set the port pins directions
#define PINA	(u8*)(0X39)     // PIN register holds the input of the port pins

#define PORTB	(u8*)(0X38)
#define DDRB	(u8*)(0X37)
#define PINB	(u8*)(0X36)

#define PORTC	(u8*)(0X35)
#define DDRC	(u8*)(0X34)
#define PINC	(u8*)(0X33)

#define PORTD	(u8*)(0X32)
#define DDRD	(u8*)(0X31)
#define PIND	(u8*)(0X30)

/*memory mapping using arrays of constant pointers with static linkage which points to volatile data*/
static u8 volatile * const PORT[NUMBER_OF_PORTS] = {PORTA, PORTB, PORTC, PORTD};
static u8 volatile * const PIN[NUMBER_OF_PORTS] = {PINA, PINB, PINC, PIND};
static u8 volatile * const DDR[NUMBER_OF_PORTS] = {DDRA, DDRB, DDRC, DDRD};

#endif /*DIO_H*/