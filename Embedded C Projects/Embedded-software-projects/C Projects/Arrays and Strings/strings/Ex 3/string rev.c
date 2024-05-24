/**
 * @file string rev.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include"string.h"
char swap(char *first, char *second);
void Rev(char *array, char arr_len);
void main()
{
    char string[30], count = 0, i = 0;
    printf("please insert your string:\n");
    fflush(stdin);
    fflush(stdout);
    gets(string);

   Rev(string, strlen(string));

   printf("%s", string);

}

char swap(char *first, char *second)
{
    *first = *first + *second;
    *second = *first - *second;
    *first = *first - *second;
}
void Rev(char *array, char arr_len)
{
    int j = arr_len - 1;

    for (int i = 0; i<arr_len/2 ; i++)
    {
        
       
           
       swap(&array[j], &array[/*min_index*/i]);

       j--;

        
    }
}
