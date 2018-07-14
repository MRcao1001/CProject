#include<stdio.h>

int main(void)
{
    int row = 1;
    int col = 1;

    do
    {
        col = 1;
        do
        {
            printf("%d×%d = %2d ",col, row, col*row);
            col++;
        }while(col <= row);
        printf("\n");
        row++;
    }while(row < 10);



    return 0;
}







