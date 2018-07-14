#include<stdio.h>

int main(void)
{
    int a = 4;
    int b = 3;
    int c = 0;
    int ret = 0;
/*
    ret = (a++ && ++b);
    //1,5,4
    printf("ret = %d\na = %d\nb = %d\n",
            ret, a, b);
*/
/*
    //0,5,3,1
    ret = (++a+b && c++);
    printf("ret = %d\na = %d\nb = %d\nc = %d\n",
            ret, a, b, c);
*/
    //0,4,1
    ret = (c++ && ++a);
    printf("ret = %d\na = %d\nc = %d\n",
            ret, a, c);

    return 0;
}
