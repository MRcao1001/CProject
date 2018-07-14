#include<stdio.h>

/**********************************************
*   输入一个年份，判断该年是否时闰年
*   闰年：
*       能被 4 整除，但不能被 100 整除
*       或者能被 400 整除
***********************************************/

int main(void)
{
    int year = 0;
    printf("input a year: ");
    scanf("%d",&year);
    getchar();

    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        printf("%d is leap year!\n",year);
    }
    else 
    {
        printf("%d isn't leap year!\n",year);
    }

    return 0;
}


