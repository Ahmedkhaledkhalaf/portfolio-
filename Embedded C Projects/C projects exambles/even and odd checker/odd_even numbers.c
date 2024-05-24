
#include <stdio.h>

int main (void)
{
    /* continoue_ is the variable used to check if the user wants to continue using the application of no */
    char continue_;
do{

    /* welcome message */
    printf ("welcome to our application\nthis program is made by Ahmed Khaled");

    /* message tells the user to enter a number */
    printf("please enter a number!\n");

    /* declaration and initialization of the variable */
    int number = 0;

    /* order to take the number */
    scanf("%d", &number);
/**
* @brief: function that divide the number over two and save it as integer.
* @param: x is the reminder after division by two.
*/
    int x = number / 2;

    /**
* @brief: function that multiply the number by two.
* @param: y is the reminder after multiplication by two.
*/
    int y = x * 2;
/**
* @brief: condition that examine if the number remains as it was.
*/
    if (y==number)
    {
        printf("The number is even = 1\nThe number is odd = 0\n");
    }

    else
    {
        printf("The number is even = 0\nThe number is odd = 1\n");
    }
    printf("do you want to continue?\ny.yes\tn.no\n");


    fflush(stdin);
    scanf("%c", &continue_);
  }
  while(continue_=='y');
}
