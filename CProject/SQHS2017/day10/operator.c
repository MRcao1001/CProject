#include<stdio.h>

int main(void)
{
    int a = 7;
    int *pa = &a;
    int *pb = &a;
#if 0
    a += 5;
    printf("a   = %d\n", a);    //12
    printf("*pa = %d\n", *pa);  //12 
#else
    *pa += 5;
    printf("a   = %d\n", a);    //12
    printf("*pa = %d\n", *pa);  //12
#endif


    return 0;
}


