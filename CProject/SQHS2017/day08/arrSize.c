#include<stdio.h>

#define LEN 5

int main(void)
{
    int arr[LEN] = {0};
    int i = 0;

    for(i=0; i<LEN; ++i)
    {
        printf("sizeof(arr[%d]) = %ld\n", i, sizeof(arr[i]));
    }
    
    printf("sizeof(arr) = %ld\n", sizeof(arr)); 

    return 0;
}













