/**
 * @file String length calc.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

void main()
{
    char string[30], count = 0, i = 0;
    printf("please insert your string:\n");
    fflush(stdin);
    fflush(stdout);
    gets(string);

    while (string[i] != 0)
    {
        count++;
        i++;
    }

    printf("the length of the string is = %d", count);
    
}