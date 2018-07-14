#include<stdio.h>

int main(void)
{
    int a = 12;

    //int *p; p = &a;
    int *p = &a;

    printf("&a = %p\n", &a);
    printf("p  = %p\n", p);
    printf("&p = %p\n", &p);


    return 0;
}





