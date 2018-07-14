#include<stdio.h>

//输入一个数，判断该数是否是素数

int main(void)
{
    int iNum = 0;
    int i = 2;

    printf("input a integer: ");
    scanf("%d",&iNum);
    getchar();

    while(i < iNum)
    {
        if(iNum % i == 0)
            break;
        i++;
    }
    if(i >= iNum)
        printf("%d is primer number!\n",iNum);
    else
        printf("%d isn't primer number!\n",iNum);

    return 0;
}
