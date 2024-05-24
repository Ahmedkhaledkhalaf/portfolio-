#include <stdio.h>


/*prototype of the functions */


int swap(int *x, int *y);
int sorting_selection(int *ptr, int len);



int main()
{
    int length = 0;
    int arr_1[20];
    printf ("please enter the length of the array\t");
    scanf("%d", &length);
    printf ("\nplease enter the elements of the array\t");
    for (int i = 0; i < length ; i++)
    {
        scanf("%d", &arr_1[i]);
    }


     sorting_selection(arr_1, length);

    printf ("\nthe result of selection is\n");
 for (int i = 0; i < length ; i++)
    {
       printf("%d\t", arr_1[i]);
    }
   printf("\nthe MAx number is %d and its position is %d" , arr_1[length-1], length-1);

   printf("\nthe Min number is %d and its position is %d", arr_1[0], 0);

}
int sorting_selection(int *ptr, int len)
{
    for (int i = 0 ; i < len; i++)
    {
       for(int min = 0; min < len; min++)

       {if(ptr[i] < ptr[min])
        {
            swap(&ptr[i],&ptr[min]);
        }
        else
        {
            continue;

        }

    }

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

