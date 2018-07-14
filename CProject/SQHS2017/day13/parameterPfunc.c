#include<stdio.h>

int addSum(int x, int y)
{
    return x+y;
}

int main(void)
{
    //int (*pfunc)(int a, int b) = addSum;
    int (*pfunc)(int, int) = addSum;

    printf("%d\n",pfunc(4,5));
    printf("%d\n",(*pfunc)(5,7));

    return 0;
}

