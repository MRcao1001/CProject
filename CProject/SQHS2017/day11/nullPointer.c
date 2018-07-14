#include<stdio.h>

int main(void)
{
    char ch = '0';

    char *pa = NULL;

    char *pb = &ch;
    *pb = NULL;

    printf("pa = %p\n", pa);
    printf("pb = %p\n", pb);
    printf("*pb = %d\n", *pb);


    return 0;
}


