#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define LEN 7

int main(void)
{
    int arr[LEN] = {0};
    int i = 0;
    int iNum = 0;

    printf("input a integer: ");
    scanf("%d", &iNum);
    getchar();

    srand(time(NULL));
    for(i=0; i<LEN; ++i)
    {
        arr[i] = rand()%50;
        printf("%4d", arr[i]);
    }
    printf("\n");

    for(i=0; i<LEN; ++i)
    {
        if(arr[i] == iNum)
        {
            printf("arr[%d] = %d\n", i, arr[i]);
            break;
        }
    }
    if(LEN == i)
        printf("not exist!\n");


    return 0;
}






