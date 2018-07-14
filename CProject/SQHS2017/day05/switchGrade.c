#include<stdio.h>

/*****************************************
*   输入成绩，成绩进行等级评定
*   百分制：
*       100:A
*       90~99:A
*       80~89:B
*       70~79:C
*       60~69:D
*       0~50:E
******************************************/

int main(void)
{
    int iScore = 0;
    
    printf("input score: ");
    scanf("%d",&iScore);
    getchar();
    
    //数据有效性判断
    if(iScore > 100 || iScore < 0)
    {
        printf("the score is error!\n");
        return -1;
    }

    switch(iScore / 10)
    {
        case 10:
        case 9:
        {
            printf("9--A\n");
            break;
        }
        case 8:
        {
            printf("8--B\n");
            break;
        }
        case 7:
        {
            printf("7--C\n");
            break;
        }
        case 6:
        {
            printf("6--D\n");
            break;
        }
        default:
        {
            printf("<6--E\n");
            break;
        }
    }

    return 0;
}


