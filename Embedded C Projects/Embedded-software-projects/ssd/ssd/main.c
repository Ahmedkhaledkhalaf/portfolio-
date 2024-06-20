/*
 * ssd.c
 *
 * Created: 10/28/2022 10:33:48 PM
 * Author : Eng Ahmed khaled
 */ 


#include "DIO_CONFIG.h"
#include "SSD_CONFIG.h"
#include "BIT_MATH.h"
#include "DATA_TYPES.h"

int main(void)
{
	SSD_INIT();
	SSD_displayNOM(9,1);
    /* Replace with your application code */
    while (1) 
    {
		SSD_DisplayMultiNom(37);
    }
}

