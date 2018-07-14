#include<stdio.h>

int main(void)
{
    int a = 12;
    //占位符的个数和变量的个数要一一对应
    printf("a = %d\n",a);

    //int b=c=d=5;  ///Error
    int b,c,d;
    //b = c = d = 5;
    b = 5; 
    c = 5; 
    d = 5;
    printf("%d--%d--%d\n",b,c,d);

    return 0;
}
