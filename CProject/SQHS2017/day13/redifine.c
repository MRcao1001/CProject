#include<stdio.h>

int testOne()
{
    //不允许函数嵌套定义
    int test()
    {
        printf("hello, world！\n");
        return 0;
    }

    test();
    printf("testOne ...\n");
    return 0;
}


int main(void)
{

    testOne();
    //test();
    printf("main ...\n");
    
    return 0;
}

