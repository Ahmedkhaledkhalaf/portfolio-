#include<stdio.h>


int main()
{
    /* declaration and initialization of the variables */
    int number_1 = 0;
    int number_2 = 0;
    char operator_;
    char continue_;

    /* welcome message */
    printf ("welcome to our application\nthis program is made by Ahmed Khaled\n");

do {
    /* message tells the user to enter the first number */
    printf("please enter the first number!\n");
    scanf("%d", &number_1);
    fflush(stdin);

     /* message tells the user to enter the first number */
    printf("please enter the operator!\n");
    scanf("%c", &operator_);
    fflush(stdin);

     /* message tells the user to enter the first number */
    printf("please enter the second number!\n");
    scanf("%d", &number_2);
/**
* @brief: switch case loop that using operator to occur the operation
*/
    switch (operator_)
    {
    case '+':
        {
            printf("The result = %d \n", number_1 + number_2);
          break;
        }
    case '-':
        {
           printf("The result = %d \n", number_1 - number_2);
          break;
        }
    case '*':
        {
            printf("The result = %d \n", number_1 * number_2);
          break;
        }
    case '/':
        {
            printf("The result = %d \n", number_1 / number_2);
          break;
        }


    }
     printf("do you want to continue?\ny.yes\tn.no\n");
    fflush(stdin);
    scanf("%c", &continue_);
  }
  while(continue_ == 'y');
  return 0;
}
