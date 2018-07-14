#include<stdio.h>

int main(void)
{
    int row = 0;
    int col = 0;
    char ch = 0;

    printf("input capital: ");
    scanf("%c", &ch);
    getchar();

    //控制打印的行数
    for(row='A'; row<=ch; row++)
    {
        //控制打印每行的空格数
        for(col=1; col<=ch-row; col++)
            printf(" ");
        //正序打印 ABCD...(ch-1)
        for(col='A'; col<row; col++)
            printf("%c", col);
        //逆序打印: ABCD...ch
        for( ; col>='A'; col--)
            printf("%c", col);
        printf("\n");
    }
    


    return 0;
}







