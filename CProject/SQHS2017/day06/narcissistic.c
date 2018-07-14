#include<stdio.h>

//求所有的水仙花数(3位自幂数)

int main(void)
{
    int iNum   = 100;
    int iHund  = 0;     //百位数
    int iTens  = 0;     //十位数
    int iOnes  = 0;     //个位数
    
    while(iNum < 1000)
    {
        iHund = iNum / 100;
        iTens = iNum % 100 / 10;
        iOnes = iNum % 10;
        if(iNum == iHund*iHund*iHund + iTens*iTens*iTens + iOnes*iOnes*iOnes)
            printf("%4d", iNum);
        iNum++;
    }
    printf("\n");
    return 0;
}





