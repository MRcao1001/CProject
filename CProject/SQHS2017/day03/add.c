#include<stdio.h>

int main(void)
{
    int a = 3;
    int b = 4;

    float ret = a / b;
    float ret1 = b / a;

    printf("a + b = %d\n", a+b); //7
    printf("a - b = %d\n", a-b); //-1
    printf("a * b = %d\n", a*b); //12
    printf("a / b = %d\n", a/b); //0
    printf("b / a = %d\n", b/a); //1

    printf("ret = %f\nret1 = %f\n",ret, ret1);
    return 0;
}

