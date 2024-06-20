#include "DATA_TYPES.h"
#include "DIO.h"
#include "DIO_INTERFACE.h"


void DIO_SET_PIN_DIRECTION(u8 port, u8 pin, u8 direction)
{
    switch(direction)
    {
        case IN : *DDR[port] &= ~(1<<pin);  break;
        case OUT: *DDR[port] |= (1<<pin);   break;
    }
}
void DIO_SET_PIN(u8 port, u8 pin)
{
    *PORT[port] |= (1<<pin);
}

void DIO_CLEAR_PIN(u8 port, u8 pin)
{
    *PORT[port] &= ~(1<<pin);   
}

u8 DIO_GET_PIN(u8 port, u8 pin)
{
    return ((*PIN[port] & (1<<pin)) >> pin);
}

void DIO_WRITE_PORT(u8 port, u8 value)
{
    *PORT[port] = value;
}

void DIO_WRITE_DDR(u8 port, u8 value)
{
     *DDR[port] = value;
}

u8 DIO_READ_PORT(u8 port)
{
    return (*PORT[port]);
}