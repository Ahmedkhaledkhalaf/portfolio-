#include <stdio.h>
#include "math.h"
/* declaration and initialization of the variable */
/* armistrong is the number which the user wants to check */

int armstrong =0;
/* continoue_ is the variable used to check if the user wants to continue using the application of no */
char continue_;

/*prototype of the function */
int Armstrong(int retval_1);



int main()
{
     printf("Welcome to Armstrong Checker Application!\n");
do {
     printf("Please Enter The Number!\n");
     scanf ("%d", &armstrong);

     int temp = Armstrong(armstrong); /* temp is a variable that saves the return of the function*/

     /* conditions that checks if the return value is equal to the main value */
     if (temp == armstrong)
     {
         printf("The number %d is Armstrong number\n", armstrong);
     }
     else
     {
         printf("The number %d is not Armstrong number\n", armstrong);
     }


  printf("do you want to continue?\ny.yes\tn.no\n");
    fflush(stdin);
    scanf("%c", &continue_);
}
/*condition that remains the application open if the user wants and presses the y key */
  while(continue_ == 'y');

}
/**
* @brief: Armstrong function that calculate the summation of multiplication of each digit by itself three times
* @param ones_digit is the first number of the entered number.
* @param tens_digit is the second number of the entered number.
* @param hundreds_digit is the thired number of the entered number.
*/
  int Armstrong(int retval_1)
{
    int ones_digit = 0;
    int tens_digit = 0;
    int hundreds_digit = 0;

    ones_digit = retval_1 % 10 ;
    tens_digit = (retval_1 % 100) - ones_digit;
    tens_digit = tens_digit/10;
    hundreds_digit = (retval_1 - (tens_digit + ones_digit));
    hundreds_digit = hundreds_digit / 100;
    ones_digit = pow(ones_digit,3);
    tens_digit = pow(tens_digit,3);
    hundreds_digit = pow(hundreds_digit,3);
    return (ones_digit + tens_digit + hundreds_digit);
}
