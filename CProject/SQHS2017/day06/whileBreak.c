#include<stdio.h>

int main(void)
{
    int i = 1;
    while(i < 101)
    {
        if(i % 3 == 0)
            break;  //跳出循环
        printf("i = %d\n",i);
        i++;
    }
    printf("end of while\n");
    return 0;
}
