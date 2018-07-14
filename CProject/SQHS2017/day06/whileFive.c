#include<stdio.h>

int main(void)
{
    int row = 0;
    int col = 0;
    int line = 0;

    printf("input line: ");
    scanf("%d",&line);


    while(row < line)
    {
        col = 0;
        while(col < row+1)
        {
            printf("*");
            col++; 
        }
        printf("\n");
        row++;
    }

    return 0;
}

