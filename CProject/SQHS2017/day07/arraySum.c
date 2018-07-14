#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEN 5

int main(void)
{
    //方法一：定义三个变量：iMax，iMin，iSum
    //方法二：定义一个数组: int buf[3];保存总和和最值
    int arr[LEN] = {0};
    int iSum = 0;   //和
    int iMax = 0;   //最大值
    int iMin = 0;   //最小值
    int i = 0;

    //产生随机数组
    srand(time(0));
    for(i=0; i<LEN; i++)
    {
        arr[i] = rand() % 10;
        printf("%4d", arr[i]);
    }
    printf("\n");

    iMin = arr[0];
    iMax = arr[0];
    //遍历数组找到最值，及求和
    for(i=0; i<LEN; i++)
    {
        //找最大值
        if(iMax < arr[i])
            iMax = arr[i];
        //找最小值
        if(iMin > arr[i])
            iMin = arr[i];
        //和
        iSum += arr[i];
    }

    printf("iSum = %d\niMax = %d\niMin = %d\n", iSum, iMax, iMin);
    return 0;
}
