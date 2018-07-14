#include<stdio.h>

int main(void)
{
    int arr[5] = {2,3,4,5,6};
    int i = 0;

    //输入数据保存到数组
    for(i=0; i<5; i++)
        scanf("%d", &arr[i]);

    //遍历输出数组元素
    for(i=0; i<5; i++)
    {
        printf("%3d\n", arr[i]);
    }


    return 0;
}


