#include<stdio.h>

int main(void)
{
    int iNum = 0;
    int iSum = 0;

    while(iNum < 100)
    {
        iNum++;
        if((iNum % 10 == 3) || (iNum / 10 == 3))
            continue;
        iSum += iNum;
    }

    printf("iSum = %d\n", iSum);
    return 0;
}

