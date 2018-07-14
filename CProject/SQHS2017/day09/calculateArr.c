#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

//求二维数组的总和及平均值
//二维数组每行的总和及平均值
//二维数组每列的总和及平均值

int main(void)
{
    int arr[ROW][COL] = {0};
    int rowSum = 0;    //行的和
    int colSum = 0;    //列的和
    int tolSum = 0;    //总的和
    int i = 0;
    int j = 0;

    //产生随机二维数组
    srand(time(0));
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            arr[i][j] = rand() % 10;
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }

    printf("\t总和\t平均值\n");
    //求总和及平均值
    for(i=0; i<ROW; i++)
    {
        rowSum = 0;
        colSum = 0;
        for(j=0; j<COL; j++)
        {
            tolSum += arr[i][j]; //所有的总和
            rowSum += arr[i][j]; //每行的总和
            colSum += arr[j][i]; //每列的总和
        }
        printf("row[%d]: %d\t%g\n",i, rowSum, (float)rowSum/ROW);
        printf("col[%d]: %d\t%g\n",i, colSum, (float)colSum/COL);
    }
    
    printf("tolSum: %d\t%g\n", tolSum, (float)tolSum/(ROW*COL));

#if 0
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
            printf("%3d", arr[i][j]);
        printf("\n");
    }
#endif

    return 0;
}



