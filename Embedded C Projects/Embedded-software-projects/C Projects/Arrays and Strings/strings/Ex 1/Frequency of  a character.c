/**
 * @file Frequency of  a character.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
int freq_calc(char a, char array[]);
void main()
{
    char string[30], var, freq = 0;
    printf("please insert your string:\n");
    fflush(stdin);
    fflush(stdout);
    gets(string);
    printf("please enter the character:\n");
    fflush(stdin);
    fflush(stdout);
    scanf("%c", &var);

    freq = freq_calc(var, string);

    printf("the frequency of the character '%c' in the string = %d", var, freq);


}

int freq_calc(char a, char array[])
{
    int i = 0, count = 0;

    while(array[i] != 0)
    {
        if (array[i] == a)
        {
            count++;
        }


        i++;

    }
    return count;
}

