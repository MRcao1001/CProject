#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEN 7

int main(void)
{
    int arr[LEN] = {0};
    int i = 0;
    int temp = 0;
    
    srand(time(NULL));
    for(i=0; i<LEN; i++)
    {
        arr[i] = rand() % 100;
        printf("%4d", arr[i]);
    }
    printf("\n");

    for(i=0; i<=LEN>>1; i++)
    {
        temp = arr[LEN-1-i];
        arr[LEN-1-i] = arr[i];
        arr[i] = temp;
    }

    for(i=0; i<LEN; i++)
        printf("%4d", arr[i]);
    printf("\n");

    return 0;
}
