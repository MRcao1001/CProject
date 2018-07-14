#include<stdio.h>

#define LEN 100

int main(void)
{
    int arr[LEN] = {0};
    int i = 0;          //循环变量
    int iNum = 0;       //淘汰数字
    int c = 0;          //指定从第几个小孩开始
    int iSurple = 0;    //剩余的小孩数
    int iCount = 0;     //数字自增

    printf("第几个/数字: ");
    scanf("%d/%d", &c, &iNum);


    //对小孩进行编号: 1~100
    for(i=0; i<LEN-1; i++)
        arr[i] = i + 1;

    //c-1:指定从第几个小孩开始(考虑数组下标)
    //iSurple 记录的是总的小孩数,当 iSurple = 1
    //时,剩余的一个小孩为最终赢家,游戏结束
    for(i=c-1,iSurple=LEN; iSurple>1; i++)
    {
        //当第一个表达式不成立时,iCount 不进行计数
        //即该下标对应的小孩是被淘汰的, iCount
        //不计数则直接进入下一次循环,
        if((arr[i]!=-1) && (++iCount == iNum))
        {
            //被淘汰的小孩,编号置为 -1
            arr[i] = -1;
            iSurple--;  //小孩总数 -1
            //当执行到此处时,说明有小孩被淘汰,
            //即 iCount 等于了指定的淘汰数字
            //因此将其重新置 0 开始数数
            iCount = 0; 
        }
        //当下标达到最大值时,让其从 0 重新开始
        if(i == LEN-1)
            //此处不是 0,注意for循环的执行顺序
            //表达式 3要被执行
            i = -1;    
    }

    for(i=0; i<LEN; i++)
    {
        if(arr[i] != -1)
        {
            printf("arr[%d] = %d\n", i, arr[i]);
            break;
        }
    }


    return 0;
}





