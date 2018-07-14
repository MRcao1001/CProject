#include<stdio.h>

int main(void)
{
    signed int a = -11;
    signed int b = 23;
    unsigned int c = -23;
    unsigned int d = 45;
    //c会输出一个随机值
    //无符号数的占位符是：%u
    printf("a = %d\nb = %d\nc = %u\nd = %u\n",a,b,c,d);
    return 0;
}
