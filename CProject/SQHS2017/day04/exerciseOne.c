#include<stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int max = 0;

    printf("input a,b: ");
    scanf("%d,%d,%d",&a, &b, &c);
    getchar();
    
    //两个数取最值
    //max = (a > b ? a : b);
    
    //三个数的最值

    
    max = (a>b ? (a>c ? a : c) : (b>c ? b :c));

    printf("max = %d\n", max);

    return 0;
}

