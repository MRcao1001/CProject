/*题目：猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，又多吃了一个 
      　　　第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下 
      　　　的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num =1;
    for(int i =9;i >0; i--){
        num = (num +1)*2;
        printf("第%d天有%d个桃子\n",i,num);
    }
    
    return 0;
}
