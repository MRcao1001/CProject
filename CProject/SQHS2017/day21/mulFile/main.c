//#include<stdio.h>

//函数声明,在外部定义
//int test();

#include "./public.h"

int main(void)
{
    printf("%s..\n", __func__);

    test();

    printf("end of main!\n");
    return 0;
}





