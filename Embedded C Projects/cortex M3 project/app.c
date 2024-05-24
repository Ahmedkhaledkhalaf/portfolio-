/**
 * @file app.c
 * @author Ahmed Khaled Khalaf (khalafawy22899@gmail.com)
 * @brief this app is running on Stm32f103CX cortex-M3 and a led connected to the PIN 13 at GPIO Port A;
 * @version 0.1
 * @date 2024-05-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include "STD_DataTypes.h"
/*regestes Macros*/
#define RCC_BASE      0x40021000 /*reset and clock control regeste*/
#define GPIO_BASE     0x40010800 /*general purpose input/output regester*/
#define RCC_APB2ENR   *(vuint_t32 *)(RCC_BASE + 0x18)
#define GPIO_CRH      *(vuint_t32 *)(GPIO_BASE + 0x04)
#define GPIO_ODR      *(vuint_t32 *)(GPIO_BASE + 0x0C)

//bit fields

#define RCC_IOPAEN    (1<<2)
#define GPIOA13       (1UL<<13)
/*using union and chiled strcat bitfiled to handel the regestes and pins*/
typedef union R_ODR_t
{
    vuint_t32   all_fields;
    
    struct 
    {
        vuint_t32   reserved:13; /*reserved bits*/
        vuint_t32   P_13:1;

    }Pin;
    
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIO_BASE + 0x0C);


void main(void)
{
    RCC_APB2ENR |= RCC_IOPAEN; /*Enable the clock to GPIO Port A*/
    GPIO_CRH &= 0xFF0FFFFF; /*To make sure that all fields are setted except the field we need to define as O (define pin 13 as Ouput)*/
    GPIO_CRH |= 0x00200000; /*define pin 13 as Ouput*/

    while (1) /*infinite loop */
    {
        R_ODR->Pin.P_13 = 1; /*set the pin 13 to get high voltage to the led (led on)*/
        for (uint_t32 i = 0; i < 5000; i++);
        R_ODR->Pin.P_13=0;/*reset the pin 13 to get low voltage to the led (led off)*/
        for (uint_t32 i = 0; i < 5000; i++);

    }
    
}