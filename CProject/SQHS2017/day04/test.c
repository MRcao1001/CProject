#include<stdio.h>

int main(void)
{
    //赋值运算符 高于 逗号运算符
    //int a = 2,3,4,5,6;    //Error
    int b = (6,5,4,3,2);

    //printf("a = %d\n",a);
    printf("b = %d\n",b);

    return 0;
}
