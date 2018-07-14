#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEN 7

void sortArray(int *arr, int len)
{
    int i = 0;
    int j = 0;
    int temp = 0;
#if 1
    for(i=len-1; i>0; i--)
    {
        for(j=0; j<len-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
#else
    for(i=0; i<len-1; i++)
    {
        for(j=0; j<len-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
#endif
    return;
}


void show(int *pa, int len)
{
    int i = 0;
    for(i=0; i<len; i++)
        printf("%4d", pa[i]);
    printf("\n");
}

int main(void)
{
    int arr[LEN] = {0};
    int i = 0;
    int iNum = 0;


    srand(time(0));
    for(i = 0; i < LEN - 1; i++)
    {
        arr[i] = rand() % 100;
        printf("%4d", arr[i]);
    }
    printf("\n================================================\n");
    
    sortArray(arr, LEN-1);
    show(arr, LEN-1);

    printf("input a integer: ");
    scanf("%d", &iNum);
    getchar();

    int j = 0;
    int temp = 0;
    int flag = 0;
    for(i=0; i<LEN-1; i++)
    {
        if(iNum == arr[i])
        {
            for(j=i; j<LEN-1; j++)
                arr[j] = arr[j+1];
            flag = 1;
            break;
        }
    }

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
    }

    show(arr, LEN);

    return 0;
}
