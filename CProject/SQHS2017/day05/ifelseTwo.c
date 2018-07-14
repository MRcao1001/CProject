#include<stdio.h>

/**************************************
*   任意输入一个数，判断该数是否是
*   3 和 5 的倍数！
*   步骤:
*       1. 定义一个变量保存输入的数据
*       2. 输入数据
*       3. 判断该数是否是 3 的倍数
*       4. 判断该数是否是 5 的倍数
*       5. 输出结果
***************************************/

int main(void)
{
    int iNum = 0;

    printf("input a integer: ");
    scanf("%d",&iNum);
    getchar();
#if 0
    //进行判断
    if(iNum % 3 == 0)
    {
        if(0 == iNum % 5)
        {
            printf("%d 是 3 和 5 的倍数...\n",iNum);
        }
        else
        {
            printf("%d 是 3 的倍数,不是 5 的倍数!\n",iNum);    
        }
    }
    else
    {
        if(0 == iNum % 5)
            printf("%d 是 5 的倍数,不是 3 的倍数!\n",iNum);
        else
            printf("%d 不是 3 和 5 的倍数\n",iNum);
    }
#else
    //逻辑运算符完成
    if((iNum % 5 == 0) && (iNum % 3 == 0))
    {
        printf("%d 是 3 和 5 的倍数!\n",iNum);
    }
    else
    {
        printf("%d 不是 3 和 5 的倍数!\n",iNum);
    }
#endif
    return 0;
}
