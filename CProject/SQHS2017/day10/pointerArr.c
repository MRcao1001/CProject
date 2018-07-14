#include<stdio.h>

int main(void)
{
    int arr[5] = {9,8,7,6,5};
    int *pa = arr;
    int i = 0;

    int *pi;
    pi = &i;

    for(i=0; i<5; i++)
    {
        printf("*(pa+%d) = %d\n", i, *(pa+i));
        printf("  pa[%d] = %d\n", i, pa[i]);
    }


    return 0;
}





