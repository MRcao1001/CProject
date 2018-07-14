#include<stdio.h>

int main(void)
{
    int a = 3;
    int b = 4;
    int ret = 0;
    //逗号表达式取最后一个表达式的值
    //作为逗号表达式的最终值
/*
    ret = (a++, a+b, ++b);
    //5,4,5
    printf("%d--%d--%d\n",ret, a, b);
*/
    ret = (++a, b--, a+b, b);
    //3--4--3
    printf("%d--%d--%d\n", ret, a, b);


    return 0;
}
