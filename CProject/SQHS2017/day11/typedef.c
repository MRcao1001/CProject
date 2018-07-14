#include<stdio.h>

int main(void)
{
    int arr[4] = {1,2,3,4};

    typedef int INT;

    INT a = 12;
    printf("a+4 = %d\n", a+4);

    typedef unsigned int uint;
    uint b = 55;
    printf("b = %u\n", b);

    typedef int (*pArr)[4];
    pArr parr = &arr;


    return 0;
}

