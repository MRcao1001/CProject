#include<stdio.h>

int main(void)
{
    int a = 3;
    int b = 50;
#if 0
    //if(a = (a+3 || b++))
    //对于逻辑或运算符，先算表达式1,
    //根据表达式 1 的结果，决定是否计算表达式2
    if(a=a+3||b++)
    {
        //1,50
        printf("a = %d\nb = %d\n", a, b);
    }
#else
    //if(a+= (3 || b++))
    if(a+=3||b++)
    {
        //4,50
        printf("a = %d\nb = %d\n", a, b);
    }
#endif

    return 0;
}
