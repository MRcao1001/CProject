#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int arr[16] = {0};
    int i = 0;

    //设置随机数种子
    srand(time(0));     //srand(time(NULL));
    //循环产生随机数
    for(i=0; i<15; i++)
    {
        arr[i] = rand() % 100;
    }

    //遍历输出数组元素
    for(i=0; i<15; i++)
        printf("%3d", arr[i]);
    printf("\n");

    return 0;
}
