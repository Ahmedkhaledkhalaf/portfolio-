#include <stdio.h>

/*prototype of the function */
int fibonacci(int);


int main()
{
    /* declaration and initialization of the variables */
    int fibonacci_number = 0; /* the number of elements of the fibonacci sequance */


 /* welcome message */
    printf ("welcome to our application\nthis program is made by Ahmed Khaled\n");

    printf("Please enter the number of elements:\t");
    scanf("%d",&fibonacci_number);
    printf("The fibonacci sequence is : \n");

    /**
    * @brief: iteration function (for loop) which calls the fibonacci function inside itself.
    *  @param : i is the local variable that increments and enter in the fibonacci function.
    */
    for (int i = 0; i < fibonacci_number; i++)
    {
        printf("%d\t" , fibonacci(i));

    }

    return 0;
}
 /* recursive fibonacci function that executes the fibonacci series */

int fibonacci(int i)
{

    if (i==0)
    {
        return 0;
    }
    else if (i==1)
    {
        return 1;
    }
    /* recursive function that calls the fibonacci function inside itself. */

    else
    {
        return (fibonacci(i-1)+fibonacci(i-2));
    }
}
