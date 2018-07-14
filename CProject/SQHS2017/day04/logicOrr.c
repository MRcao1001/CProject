#include<stdio.h>

int main(void)
{
    int a = 3;
    int b = 1;

    //printf("%d || %d = %d\n", a+b, b-a, (a+b)||b-a);
    
    //1,2,1
    //printf("--a || b-- = %d\n", --a || b--);

    //1,4,1
    printf("--b || b+a++ = %d\n", (--b || (b+a++)));
    printf("a = %d\nb = %d\n", a, b);
    return 0;
}

