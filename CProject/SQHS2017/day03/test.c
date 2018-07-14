#include<stdio.h>

int main(void)
{
    int a = 23;
    int b = 3;

    int ret = a % b;

    printf("%d--%d\n",ret, 23%3);

    float fNum = 23.234;
    float fNum1 = 3.14;
    //只有整数可以做取余运算
    printf("fNum = %g\n", fNum%fNum1);

    return 0;
}
