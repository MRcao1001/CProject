#include<stdio.h>

int main(void)
{
    int arr[5] = {7,6,9,4,2};
    int i = 0;

    //遍历输出数组
    for(i=0; i<5; i++)
    {
        printf("*(arr+%d) = %d\n", i, *(arr+i));
    }

    //注意与上面写法的区别
    for(i=0; i<5; i++)
    {
        printf("*arr+%d = %d\n", i, *arr+i);
    }

    return 0;
}
