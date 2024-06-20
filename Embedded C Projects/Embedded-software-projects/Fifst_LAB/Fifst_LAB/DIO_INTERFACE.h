#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "DATA_TYPES.h"

#define IN  0
#define OUT 1


/*define symbolic constants for GPIO port pins from 0 to 7*/
enum {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7};

/*define symbolic constants for GPIO ports, 4 ports (A,B,C,D)*/
enum {A, B, C, D};

void DIO_SET_PIN_DIRECTION(u8 port, u8 pin, u8 direction);
void DIO_SET_PIN(u8 port, u8 pin);
void DIO_CLEAR_PIN(u8 port, u8 pin);
u8 DIO_GET_PIN(u8 port, u8 pin);
void DIO_WRITE_PORT(u8 port, u8 value);
void DIO_WRITE_DDR(u8 port, u8 value);



#endif /*DIO_INTERFACE_H*/