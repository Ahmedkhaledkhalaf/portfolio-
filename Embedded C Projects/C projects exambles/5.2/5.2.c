#include <stdio.h>





int reverse(int *ptr, int size);
int swap(int *x, int *y);


int main()
{
   int arr[50];
int size = 0;

printf("please enter the number of elements! : \t");
   scanf("%d", &size);


    printf("please enter the elements! : \t");
   for (int i = 0 ; i<size ;i++)
    {
        scanf("%d", &arr[i]);
   }


    reverse(arr, size);


printf("\n");


     for (int i = 0 ; i<size ;i++)
    {
        printf ("%d\t", arr[i]);
    }
}



int reverse(int *ptr, int n)
{
     ; //size_of_array (ptr);
    for (int i = 0 ; i <= (n/2); i++)
    {
        swap(&ptr[i], &ptr[n-1]);
        n--;
    }
}

/**
* @brief: swap function that swaps the values of tow numbers using two variables and call by reference.
* @param x is a pointer of integer of the first number
* @param y is a pointer of integer of the second number
*/
int swap(int *x, int *y)
{
    /* logical XOR operations that swaps the values */

    *x = *x^*y;
    *y = *x^*y;
    *x = *x^*y;

    return (*x,*y);
}

