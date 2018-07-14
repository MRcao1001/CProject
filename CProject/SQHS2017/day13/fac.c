#include<stdio.h>

/*
  5! = 5*4*3*2*1 = 5 * 4! = 5 * factorial(4)
  4! = 4*3*2*1 = 4 * 3! = 4 * factorial(3)
  3! = 3*2*1 = 3 * 2! = 3 * factorial(2)
  2! = 2*1 = 2 * 1! = 2 * factorial(1)
  1! = 1;
*/
int factorial(int x)
{
    if(0 == x || 1 == x)
        return 1;
    int sum = x * factorial(x-1);
    return sum;
}

int main(void)
{
    int iNum = 0;

    printf("input a integer: ");
    scanf("%d", &iNum);

    int ret = factorial(iNum);
    printf("%d! = %d\n", iNum, ret);

    return 0;
}

