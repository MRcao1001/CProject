#include<stdio.h>

void test(void)
{
    printf("Hello, world!\n");
    return;
}

int main(void)
{
    printf("in main ...\n");

    test();
    test();
    test();
    test();

    printf("end of main ...\n");
    return 0;
}



