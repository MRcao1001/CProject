#include<stdio.h>

int main(void)
{
    int a = 456;
    //输出宽度为 6
    printf("%6d\n",a);
    //输出宽度为 7
    printf("%*d\n", 7, a);
    return 0;
}
