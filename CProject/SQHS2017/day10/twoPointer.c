#include<stdio.h>

int main(void)
{
    int a = 10;
    int *pa = &a;
    int **pb = &pa;

    printf("&a = %p\n", &a);
    printf("pa = %p\n", pa);
    printf("*pb = %p\n", *pb);
    printf("**pb = %d\n", **pb);

    return 0;
}

