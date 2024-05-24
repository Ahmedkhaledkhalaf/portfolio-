#include <stdio.h>
#include "uart.h"

unsigned char String_buffer[100] = "learn-in-depth:<Ahmed>";
unsigned char String_buffer2[100] = "learn-in-depth:<Ahmed>";

int main(void)
{
    UART_Send_string(String_buffer);
	return 0;
}
