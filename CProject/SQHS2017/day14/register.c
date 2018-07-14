#include<stdio.h>

int main(void)
{
    register int iNum = 34;

    iNum += 66;

    printf("iNum = %d\n", iNum);

    return 0;
}

