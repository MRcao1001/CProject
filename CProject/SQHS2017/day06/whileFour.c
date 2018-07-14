#include<stdio.h>

int main(void)
{
    int i = 0;
    while(i < 5)
        printf("i = %d\n",i++);
        //若该语句打印一次，则说明循环体只有一条
        printf("**i = %d\n",i);
#if 3
    while(i++ < 10)
    {
        int sum = 0;
        sum += i;
        printf("sum = %d\n",sum);
    }
    //printf("sum = %d\n",sum);     //error
#endif
    return 0;
}



