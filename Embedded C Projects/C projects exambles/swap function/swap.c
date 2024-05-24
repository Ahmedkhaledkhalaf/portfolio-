#include <stdio.h>

/*prototype of the function */
int swap(int *x, int *y);

int main()
{
    /* declaration and initialization of the variable */
    int numb_1 = 0;
    int numb_2 = 0;

    /* welcome message */
    printf ("welcome to our application\nthis program is made by Ahmed Khaled");

    printf("please enter the first number! \t");
    scanf("%d", &numb_1);

    printf("please enter the second number! \t");
    scanf("%d", &numb_2);
    /* calling of the function using addresses */
    swap(&numb_1, &numb_2);
    printf("The first number = %d \nThe second number = %d \n", numb_1 , numb_2);

    return 0;

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
