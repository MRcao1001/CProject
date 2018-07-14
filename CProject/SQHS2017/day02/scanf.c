#include<stdio.h>

int main(void)
{
    int a = 0;
    //&:取地址运算
    //将数据保存到 a 所对应的地址当中
    //"" 中不能写 \n
    scanf("%d",&a);
    //printf 可以不加 \n
    printf("a = %d\n",a);
    return 0;
}
