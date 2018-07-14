#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEN 7

int initArray(int *arr)
{
    int i = 0;
    srand(time(0));
    for(i=0; i<LEN; i++)
        arr[i] = rand() % 100;
    return 0;
}

int showArray(int *arr)
{
    int i = 0;
    for(i=0; i<LEN; i++)
        printf("%4d", *(arr+i));
    printf("\n");
    return 0;
}

//由小到到大的顺序
int selectSort(int *arr)
{
    int i = 0;
    int j = 0;
    int min = 0;
    int temp = 0;
    for(i=0; i<LEN-1; i++)
    {
        min = i;    //假设当前数为最小值,记录其下标
        for(j=i+1; j<LEN; j++)
        {
            if(arr[min] > arr[j])
                min = j;    //记录最小值的下标
        }
        //说明 min 对应的值,为最小值
        //因此进行数据交换,将最小值往前放
        if(min != i)
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    return 0;
}

int main(void)
{
    int arr[LEN] = {0};

    initArray(arr);     //产生随机数组
    showArray(arr);     //打印数组

    //选择排序
    selectSort(arr);
    showArray(arr);     //排序后输出
    return 0;
}


