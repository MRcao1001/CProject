#include<stdio.h>

int main(void)
{
    int a = 19;
    int *pa = NULL;
    int *pb = &a;
    int *pc;
#if 0
    printf("&a  = %p\n", &a);
    printf("pa  = %p\n", pa);
    printf("pb  = %p\n", pb);
    printf("&pa = %p\n", &pa);
#endif

    printf("a = %d\n", a);
    printf("*pb = %d\n", *pb);
    //printf("*pa = %d\n", *pa);  //Error
    //printf("*pc = %d\n", *pc);  //Error

    return 0;
}








