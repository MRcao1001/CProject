#include<stdio.h>

int main(void)
{
    int iNum = 0;
    int iMul = 1;

    printf("input a integer: ");
    scanf("%d", &iNum);
    getchar();

    //判断数据：0 / 1
    if(0 == iNum || 1 == iNum)
    {
        printf("%d! = %d\n",iNum, 1);
        return -1;
    }
    int i = iNum;
    //求 iNum 的阶乘
    while(iNum > 0)
    {
        iMul *= iNum;
        iNum--;
    }
    printf("%d! = %d\n", i, iMul);
 /*
    i = 1;
    while(i < iNum+1)
    {
        iMul *= i;
        i++;
    }
*/
    return 0;
}

