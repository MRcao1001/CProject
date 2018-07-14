#include<stdio.h>

#define TEST    //空宏

int main(void)
{
    //#undef TEST
    #ifdef TEST
    printf("TEST exist!\n");
    #endif

    #ifndef TEST
    printf("TEST not exist\n");
    #endif

    return 0;
}

