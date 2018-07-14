#include<stdio.h>

int main(void)
{
    int a = 3;
    int b = 5;

    #if (a<b)
    printf("a<b: ");
    printf("%d--%d\n", a, b);
    #elif (a>b)
    printf("a>b: ");
    printf("%d--%d\n", a, b);
    #else
    printf("a=b: ");
    printf("%d--%d\n", a, b);
    #endif


    return 0;
}








