#include <stdio.h>

int main()
{
/* declaration and initialization of the variable */
   unsigned int number = 0;
    int nth_bit_number = 0;
    int toggle=0;
    char continue_;

/* welcome message */
    printf ("welcome to our application\nthis program is made by Ahmed Khaled\n");
do{
/* message tells the user to enter a number */
    printf("please enter a number!\n");

/* order to take the number */
    scanf("%d", &number);

    printf("please enter the number of nth bit to toggle (0-31)!\n");

/* order to take the number */
    scanf("%d", &nth_bit_number);

    toggle = 1 << nth_bit_number;
    number = number ^ toggle;
    printf("%d\n",number);
    printf("do you want to continue?\ny.yes\tn.no\n");
    fflush(stdin);
    scanf("%c", &continue_);
  }
  while(continue_ == 'y');
  return 0;
}
