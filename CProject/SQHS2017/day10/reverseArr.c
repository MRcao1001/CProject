#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEN 8

int initArray(int arr[])
{
    int i = 0;
    srand(time(0));
    for(i=0; i<LEN; i++)
        arr[i] = rand() % 100;
    return 0;
}

void showArray(int arr[])
{
    int i =  0;
    for(i=0; i<LEN; i++)
        printf("%3d", arr[i]);
    printf("\n");
    return;
}

int main(void)
{
    int arr[LEN] = {0};
    int *pa = arr;
    int *pb = &arr[LEN-1];
    int temp = 0;

    //产生随机数组
    initArray(arr);

    //倒置前打印数组
    showArray(arr);

    //倒置数组
    for(pa=arr,pb=&arr[LEN-1]; pa<pb; pa++,pb--)
    {
        temp = *pa;
        *pa  = *pb;
        *pb  = temp;
    }

    //倒置后打印数组
    showArray(arr);
    return 0;
}


