#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
/******************************************
*	模拟简易自动售货机
*
******************************************/
int main(void)
{
    int iChoice = 0;
    int money = 0;
    int pay = 0;
    while(1)
    {
        system("clear");
        printf("1. 红牛(￥5)\n");
        printf("2. 农夫山泉(￥2)\n");
        printf("3. 营养快线(￥4)\n");
        printf("4. 脉动(￥3)\n");
        printf("input choice: ");
        scanf("%d",&iChoice);
        getchar();
        printf("请投币: ");
        scanf("%d", &pay);
        getchar();
        money += pay;
        switch(iChoice)
        {
            case 1:
            {
                if(money >= 5)
                {
                    printf("红牛\n");
                    printf("找零: %d\n",money-5);
                    money = 0;
                }
                else
                {
                    printf("余额不足!\n");
                    printf("请重新选择,继续投币!\n");
                }
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            default:
            {
                printf("已售光,请重新选择!\n");
                break;
            }
        }
    }
    return 0;
}

