#include <stdio.h>



struct variables
{
    enum constants
{
  const_1 = 5 ,
  const_2 = 20,
  const_3 = 60
};
   int var ;
}x;

int edit_func (int *ptr);

int main()
{


printf("please enter a number! : \t");
scanf("%d", &x);
printf("%d\t%d\t%d\t%d\n",const_1, const_2, const_3, x );
edit_func(&x );
printf("%d\t",x );

}


int edit_func (int *ptr)
{
    *ptr+=1;


}
