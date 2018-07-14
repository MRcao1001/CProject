#include<stdio.h>

/************************************************
 *a. 求 1~100 的累加和
 *b. 求 100 以内所有奇数的和
 *c. 求 100 以内所有偶数的和
 ************************************************/

int main(void)
{
    int iNum = 0;
    int iSum = 0;       //所有数的和
    int iOddSum  = 0;   //所有奇数的和
    int iEvenSum = 0;   //所有偶数的和

    //1. 求 100 以内所有数的和
    while(iNum < 101)
    {
        iSum += iNum;
        iNum++;
    }
    printf("1+2+3+...+99+100 = %d\n", iSum);
    //2. 求 100 以内所有奇数的和
    //方法一
    iNum = 1;
    while(iNum < 101)
    {
        iOddSum += iNum;
        iNum += 2;
    }
    printf("1+3+5+...+97+99  = %d\n", iOddSum);
    
    //方法二
    iNum = 0;
    iOddSum = 0;
    while(iNum < 101)
    {
        if(iNum % 2 == 1)
            iOddSum += iNum;
        iNum++;
    }
    printf("1+3+5+...+97+99  = %d\n", iOddSum);
    //3. 求 100 以内所有偶数的和
    //方法一
    iNum = 0;
    while(iNum < 101)
    {
        iEvenSum += iNum;
        iNum += 2;
    }
    printf("2+4+6+...+98+100 = %d\n",iEvenSum);
    //方法二
    iNum = 0;
    iEvenSum = 0;
    while(iNum < 101)
    {
        if(iNum % 2 == 0)
            iEvenSum += iNum;
        iNum++;
    }
    printf("2+4+6+...+98+100 = %d\n",iEvenSum);
    //方法三
    //采用switch的形式求奇数，偶数和
    iNum = 0;
    iOddSum = 0;
    iEvenSum = 0;
    while(iNum < 101)
    {
        switch(iNum % 2)
        {
            case 0:
            {
                iEvenSum += iNum;
                break;
            }
            case 1:
            {
                iOddSum += iNum;
                break;
            }
        }
        iNum++;
    }
    printf("2+4+6+...+98+100 = %d\n",iEvenSum);
    printf("1+3+5+...+97+99  = %d\n", iOddSum);
    //方法四
    //采用位运算：位与
    iNum = 0;
    iOddSum = 0;
    iEvenSum = 0;
    while(iNum < 101)
    {
        switch(iNum & 1)
        {
            case 0:
            {
                iEvenSum += iNum;
                break;
            }
            case 1:
            {
                iOddSum += iNum;
                break;
            }
        }
        iNum++;
    }
    printf("\n\n采用位与运算:\n");
    printf("2+4+6+...+98+100 = %d\n",iEvenSum);
    printf("1+3+5+...+97+99  = %d\n", iOddSum);

    return 0;
}












