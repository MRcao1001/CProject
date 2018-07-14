#include<stdio.h>

//int factorial(int iNum);
int factorial(int);

//int factorial();  //Error

int main(void)
{
    printf("%s ...\n", __func__);
    factorial(5);
    return 0;
}

int factorial(int iNum)
{
    int i = 0;
    int mul = 1;
    for(i=1; i<iNum+1; i++)
        mul *= i;
    printf("%s: %d\n", __func__, mul);
    return mul;
}


