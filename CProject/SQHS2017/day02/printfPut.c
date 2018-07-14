#include<stdio.h>

int main(void)
{
    int iNum = 12;
    char ch  = 'R';
    float fNum = 3.14;
    printf("%d--%c--%f\n",iNum, ch, fNum);
    //编译器会对以下代码进行优化
    //将占位符和变量严格一一对应起来
    //printf("%d--%c--%f\n",fNum, iNum, ch);
    return 0;
}
