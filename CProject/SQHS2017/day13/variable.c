#include<stdio.h>

int i = 7;  //全局变量
extern int k;
extern int getSum(int, int);    //函数声明

int k = 4;

int main(void)
{
    printf("i = %d\n k = %d\n", i, k);
    printf("%d\n",getSum(6,4));
    return 0;
}

int getSum(int x, int y)
{
    //extern int k = 4;     //error
    //extern int k;   //OK,声明变量
    return (i+x+y+k);
}

