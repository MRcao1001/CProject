#include<stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int max = 0;
    
    printf("input a,b: ");
    scanf("%d,%d",&a, &b);
    getchar();

    //max = (a>b ? a : b);
    if(a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }

    printf("max = %d\n",max);
    return 0;
}
