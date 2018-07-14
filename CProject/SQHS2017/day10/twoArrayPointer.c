#include<stdio.h>

int main(void)
{
    int arr[3][4] = {0};

    int (*pa)[4] = arr;
    
    int i = 0;
    int j = 0;

    //
    for(i=0;  i<3*4; i++)
    {
        (*pa)[i] = i + 1;
        printf("%d\n", (*pa)[i]);
    }

    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
            printf("pa[%d][%d] = %d\n", i, j, pa[i][j]);
    }

    return 0;
}

