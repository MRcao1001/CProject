#include<stdio.h>

/***************************************
*   输入学生成绩，进行等级评定：
*   百分制：
*       90~100:A
*       80~90:B
*       70~80:C
*       60~70:D
*       0~50:E
****************************************/

int main(void)
{
    int iScore = 0;

    printf("input score: ");
    scanf("%d",&iScore);
    getchar();

    //数据有效性的判断
    if(iScore < 0 || iScore > 100)
    {
        printf("input score error!\n");
        return -1;
    }

    //成绩等级评定
    if(iScore >= 90 && iScore <= 100)
    {
        printf("\nA\n");
    }
    else if(iScore >= 80 && iScore < 90)
    {
        printf("\nB\n");
    }
    else if((iScore >= 70) && (iScore < 80))
    {
        printf("\nC\n");
    }
    else if((iScore >= 60) && (iScore < 70))
    {
        printf("\nD\n");
    }
    else
    {
        printf("\nE\n");
    }
    return 0;
}
