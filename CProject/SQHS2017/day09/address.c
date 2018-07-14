#include<stdio.h>

int main(void)
{
    int arr[2][3];
    int i = 0;
    int j = 0;

    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
        }
        printf("arr[%d]   = %p\n", i, arr[i]);
        printf("arr[%d]+1 = %p\n", i, arr[i]+1);
        printf("arr+%d    = %p\n", i, arr+i);
        printf("*(arr+%d) = %p\n", i, *(arr+i));
    }


    return 0;
}





