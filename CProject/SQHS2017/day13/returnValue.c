#include<stdio.h>

int getSum(int x, int y)
{
    //系统宏,打印当前语句所在函数名称
    printf("%s\n", __func__);
    return (x+y);
}

int main(void)
{
    
    printf("%s\n", __func__);
    //若函数返回值在当前函数中只用到一次,
    //则可以使用以下形式
    getSum(4,5);
    printf("%d\n", getSum(4,5));
    //若函数返回值需要多次用到,则需要相同
    //类型的变量来记录返回值
    int ret = getSum(4,5);
    printf("ret = %d\n", ret);

    return 0;
}

