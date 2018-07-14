#include<stdio.h>

static int a;   //默认初始化为 0

int main(void)
{
    int b;  //未知
    static int c;   //默认初始化为 0

    printf("a = %d\nb = %d\nc = %d\n", a, b, c);

    return 0;
}

