#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEN 7

void bubleSort(int arr[])
{
    int row = 0;    //控制外层循环
    int col = 0;    //控制内层循环
    int temp = 0;   //中间变量,用于数据交换
    //控制比较的轮数
    for(row=0; row<LEN-1; row++)
    {
        //控制每轮比较的次数,即
        //控制每轮参与比较的元素的个数
        for(col=0; col<LEN-1-row; col++)
        {
            //从大到小排序
            if(arr[col] > arr[col+1])
            {
                //交换数据,将大数向后移动
                temp       = arr[col];
                arr[col]   = arr[col+1];
                arr[col+1] = temp;
            }
        }
    }
    return;
}

int main(void)
{
    int arr[LEN] = {0};
    int i = 0;

    //产生随机数组，并输出数组
    srand(time(0));
    for(i=0; i<LEN; ++i)
    {
        arr[i] = rand() % 100;
        if(0 == arr[i])
        {
            --i;
            continue;
        }
        printf("%4d", arr[i]);
    }
    printf("\n\n");
    
    //数组排序
    bubleSort(arr);

    for(i=0; i<LEN; ++i)
        printf("%4d", arr[i]);
    printf("\n\n");

    return 0;
}




