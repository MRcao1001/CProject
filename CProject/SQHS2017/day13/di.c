#include<stdio.h>
int i = 0;  //全局变量
//此处相当于死循环
int test()
{
    printf("hello, world\n");
    if(++i == 5)
        return 0;
    test();
    return 0;
}

int main(void)
{
    printf("main ...\n");
    test();
    return 0;
}
