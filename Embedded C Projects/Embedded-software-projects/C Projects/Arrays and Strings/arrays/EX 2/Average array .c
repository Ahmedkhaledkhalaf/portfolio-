/**
 * @file Average array .c
 * @author Ahmed khaled khalaf (https://github.com/Ahmedkhaledkhalaf)
 * @brief
 * @version 0.1
 * @date 2024-03-16
 *
 * @copyright Copyright (c) 2024
 *
 */




#include <stdio.h>
void Array_Print(int x, float array[]);
void Array_setting(int x, float array[]);
float Avg(int x, float array[]);

int main()
{
    int n = 0;
    float avrg = 0;
    printf("please enter the number of elements n = \t");

    scanf("%d", &n);

    float array[n];

    Array_setting(n, array);

    avrg = Avg(n, array);
    printf("the average of your array elements = %.3f", avrg);

    return 0;





}


void Array_Print(int x, float array[])
{
    printf("\nThe elements of your array are: \n");
    for (int i = 0; i<x; i++)
    {


            printf("%.2f\t", array[i]);

        printf("\t");
    }

            printf("\n");

}
void Array_setting(int x, float array[])
{

printf("please enter the elements of your array \n");
    for (int i = 0; i<x; i++)
    {

            scanf("%f", &array[i]);

    }

    Array_Print(x, array);

}

float Avg(int x, float array[])
{
    float temp = 0;
    for (int i = 0; i<x; i++)
    {

            temp += array[i];

    }

    temp /= x;

    return temp;
}

