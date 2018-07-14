#include<stdio.h>

int test(void)
{
    printf("CHINA ...\n");
    return 0;
}

int main(void)
{
    //定义一个函数指针
    int (*pFunc)();

    //函数指针的初始化
    pFunc = test;

    //函数指针的使用
    pFunc();    //方式一
    (*pFunc)(); //方式二

    return 0;
}


