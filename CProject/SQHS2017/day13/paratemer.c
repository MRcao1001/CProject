#include<stdio.h>
#include<assert.h>

//注意以下两种写法时，返回值的区别
//float getSum(float x, int y)
float getSum(int x, float y)
{
    return (x+y);
}


int main(void)
{
    int a = 3;
    float b = 3.22;

    float ret = getSum(a,b);
    printf("%f\n", ret);

    return 0;
}
