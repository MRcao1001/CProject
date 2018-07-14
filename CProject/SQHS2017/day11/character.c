#include<stdio.h>

int main(void)
{
    char buf[16] = {"A\tBi\\CD\bDE\rFGH\n"};

    printf("%s", buf);
    printf("%%");


    return 0;
}


