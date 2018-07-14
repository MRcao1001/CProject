#include<stdio.h>

int hello();    //函数声明一般放在此处

int main(void)
{
    //int hello();
    printf("%s ...\n", __func__);
    //int hello();    //函数声明
    hello();        //函数调用
    return 0;
}

//int hello();  //error, 放在调用之前
//函数定义
int hello()
{
    printf("hello, world!\n");
    return 0;
}

