#include<stdio.h>

int main(void)
{
    int a = 0;

    printf("input a: ");
    scanf("%d",&a);
    getchar();

    //30~40
    // 30 <= a:的结果有两种：0 或 1
    // 0 或 1 都小于 40,故该表达式为
    // 真值表达式
    if(30 <= a <= 40)
    {
        printf("%d 在 30～40 之间!\n",a);
        //printf("%d\n", (30<= a <= 40));
    }
    if(30 <= a && a<= 40)
    {
        printf("%d in [30,40]\n",a);
    }
    printf("end if\n");
    return 0;
}

