#include<stdio.h>

//九九乘法表

int main(void)
{
    int row = 1;
    int col = 1;

    while(row < 10)
    {
        col = 1;
        while(col <= row)
        {
            printf("%d×%d = %2d ",col, row, row*col);
            col++;
        }
        printf("\n");
        row++;
    }

    return 0;
}

