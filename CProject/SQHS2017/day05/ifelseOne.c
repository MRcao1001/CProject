#include<stdio.h>
/********************************************
*   任意输入三个数，求其最大值
*   一：
*       条件运算符
*   二：
*       if ～ else 语句实现
*********************************************/

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int max = 0;

    printf("input a,b,c: ");
    scanf("%d,%d,%d",&a, &b, &c);
    getchar();  //吸收回车
    
    //采用 条件运算符 完成
    //max = ((a>b) ? (a>c?a:c) : (b>c?mZ:c));

    //采用 if～else 语句完成
    if(a > b)
    {
        if(a > c)
            max = a;
        else
            max = c;
    }
    else 
    {
        if(b > c)
            max = b;
        else 
            max = c;
    }
    printf("\nthe max value is: %d\n", max);
    return 0;
}

