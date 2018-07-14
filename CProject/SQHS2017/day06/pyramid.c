#include<stdio.h>

int main(void)
{
    int row = 1;    //控制行
    int col = 1;    //控制列
    int iNum = 0;   //要打印的行数

    printf("input line: ");
    scanf("%d", &iNum);
    getchar();
    
    //控制行
    while(row < iNum + 1)
    {
        //控制每行的空格数量
        col = 1;
        while(col <= iNum - row)
        {
            printf(" ");
            col++;
        }
        
        //控制每行的 * 数量
        col = 1;
        while(col <= (2*row-1))
        {
            printf("*");
            col++;
        }
        printf("\n");   //进入下一行
        row++;
    }
    

    return 0;
}




