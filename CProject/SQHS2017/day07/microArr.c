#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEN 10

int main(void)
{
    int arr[LEN] = {0};
    int i = 0;

    srand(time(NULL));
    for(i = 0; i < LEN; i++)
    {
        arr[i] = rand() % 100;
        printf("%4d", arr[i]);
    }
    printf("\n");
    return 0;
}
