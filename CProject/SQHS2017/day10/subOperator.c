#include<stdio.h>

int main(void)
{
    int a = 12;
    int b = 24;

    int *pa = &a;
    int *pb = &b;

    printf("%p - %p = %ld\n", pa, pb, pa-pb);
    printf("%p - %p = %ld\n", pb, pa, pb-pa);
    printf("%d - %d = %d\n", *pa, *pb, *pa-*pb);


    return 0;
}





