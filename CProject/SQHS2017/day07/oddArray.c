#include<stdio.h>

//向数组中存入奇数或者偶数

int main(void)
{
    int arr[15] = {0};
    int i = 0;  //循环变量

    //向数组中存入奇数
    for(i=0; i<15; i++)
    {
        arr[i] = 2 * i + 1;
    }

    //循环输出数组元素
    for(i=0; i<15; i++)
        printf("%4d", arr[i]);
    printf("\n");

    return 0;
}
