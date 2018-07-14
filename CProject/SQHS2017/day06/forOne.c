#include<stdio.h>

int main(void)
{
    int iNum = 0;
    int i = 0;

    printf("input a integer: ");
    scanf("%d",&iNum);
    getchar();

    for(i=2; i<iNum; i++)
    {
        if(0 == iNum % i)
            break;
    }
    if(iNum <= i)
        printf("%d 是素数...\n",iNum);
    else
        printf("%d 不是素数...\n",iNum);
        
    return 0;
}


