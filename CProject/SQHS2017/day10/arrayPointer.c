#include<stdio.h>

int main(void)
{
    int arr[4] = {12,34,56,78};
    int *pBuf[4] = {NULL};  //指针数组
    int (*pArr)[4] = NULL;  //数组指针,又称行指针
    int i = 0;

    for(i=0; i<4; i++)
    {
        //pBuf 里的每一个元素都是指针类型
        pBuf[i] = &arr[i];
    }
    
    printf("%d\n", *pBuf[2]);

    pArr = &arr;
    
    printf("%d\n",(*pArr)[0]);
    printf("%d\n",(*pArr)[1]);
    printf("%d\n",(*pArr)[2]);

    return 0;
}

