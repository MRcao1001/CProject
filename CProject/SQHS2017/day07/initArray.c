#include<stdio.h>

int main(void)
{
    //全部初始化
    int arr[5] = {1,2,3,4,5};

    //部分初始化
    int buf[4] = {66,33};

    //访问数组元素
    printf("arr[2] = %d\n", arr[2]);
    printf("buf[1] = %d\n", buf[1]);
    printf("buf[3] = %d\n", buf[3]);

    //定义数组不初始化
    int arr1[3];
    printf("arr1[2] = %d\n", arr1[2]);

    //指定数组具体初始化
    int iBuf[6] = {[2]=22, [4]=44, [0]=11};
    printf("iBuf[2] = %d\n", iBuf[2]);
    printf("iBuf[3] = %d\n", iBuf[3]);

    return 0;
}

