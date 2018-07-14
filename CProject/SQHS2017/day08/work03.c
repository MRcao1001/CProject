#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEN 7

//产生随机数组
void randArray(int arr[])
{
    int i = 0;
    srand(time(0));
    for(i=0; i<LEN-1; i++)
    {
        arr[i] = rand() % 100;
        if(0 == arr[i]) //除去随机数 0
        {
            --i;
            continue;
        }
    }
    return;
}

//遍历输出数组
void showArray(int arr[])
{
    int i = 0;
    for(i=0; i<LEN; i++)
        printf("%4d", arr[i]);
    printf("\n");
    return;
}

//数组元素排序
int bubleSort(int arr[])
{
    int i = 0;
    int j = 0;
    int temp = 0;
    int len = LEN-1;
    for(i=0; i<LEN-2; i++)
    {
        for(j=0; j<LEN-2-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp     = arr[j+1];
                arr[j+1] = arr[j];
                arr[j]   = temp;
            }
        }
    }
    return 0;
}

int main(void)
{
    int arr[LEN] = {0};
    int i = 0;
    int iNum = 0;
    int flag = 0;

    //产生随机数组
    randArray(arr);
    
    //排序前输出
    showArray(arr);

    //排序后
    bubleSort(arr);
    showArray(arr);

    printf("input a integer: ");
    scanf("%d", &iNum);

    //遍历数组,查找 iNum 是否存在,存在则删除
    for(i=0; i<LEN-1; i++)
    {
        if(iNum == arr[i])
        {
            //将后面的数据向前移动，补填空位
            for(; i<LEN-1; i++)
                arr[i] = arr[i+1];
            flag = 1;
            break;
        }
    }
    //若 iNum 不存在,则插入
    int j = 0;
    if(!flag)
    {
        for(i=0; i<LEN-1; i++)
        {
            if(iNum < arr[i])
            {
                for(j=LEN-1; j>i; j--)
                    arr[j] = arr[j-1];
                arr[j] = iNum;
                break;
            }
        }
        //处理当 iNum 大于数组中所有元素时
        if(i == LEN-1)
            arr[LEN-1] = iNum;
    }

    //插入或者删除后输出数组
    showArray(arr);
    
    return 0;
}


