#include<stdio.h>

int main(void)
{
    int a = 0;
    int b = 1;

    //printf("!%d = %d\n", a, !a);
    //printf("!%d = %d\n", b, !b);
    
    //1
    printf("!(%d>%d) = %d\n", a, b, !(a>b));
    return 0;
}

