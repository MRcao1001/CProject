#include<stdio.h>

//auto int c = 66;  //error
int c = 66;

int test(void)
{
    int a =  12;
    auto int b = 11;

    printf("a = %d\nb = %d\n", a, b);

    b += a;

    printf("b = %d\n", b);

    printf("c = %d\n", c);

    return 0;
}

