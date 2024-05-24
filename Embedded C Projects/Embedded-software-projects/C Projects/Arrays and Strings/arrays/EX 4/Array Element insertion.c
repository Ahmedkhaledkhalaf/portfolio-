/**
 * @file Array Element insertion.c
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
void Element_insertion(int n, int location, int value, float O_Arr[n], float N_Arr[n+1]);
void main()
{

    int n = 0, element_no = 0, element_value = 0 ;
    printf("please enter the number of elements n = \t");
    scanf("%d", &n);

    float Original_Array[n];
    Array_setting(n, Original_Array);
    printf("\n");
    printf("please enter the location of the element to be inserted = \t");
    scanf("%d", &element_no);
    printf("please enter the element = \t");
    scanf("%d", &element_value);
   float New_Array[n+1];

   Element_insertion(n, element_no, element_value, Original_Array, New_Array);



    
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

    printf("\n your original array is:\n");
    Array_Print(x, array);

}

void Element_insertion(int n, int location, int value, float O_Arr[], float N_Arr[])
{
    for (int i = 0; i < n+1; i++)
    {
        if (i == (location-1))
        {
            N_Arr[i] = value;
        }

        else if (i>(location-1))
        {
            N_Arr[i] = O_Arr[i-1];
        }

        else 
        {
            N_Arr[i] = O_Arr[i];
        }
        
        
    }

    printf("\n your New array is:\n");
    Array_Print(n+1, N_Arr);

    
}