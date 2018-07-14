#include<stdio.h>

int main(void)
{
    int iNum = 0;
    int iSum = 0;

    do
    {
        iSum += iNum;
        iNum++;
    }while(iNum < 101);

    printf("iSum = %d\n",iSum);

    return 0;
}


