#include<stdio.h>

int main(void)
{
    int a = 0;

    printf("input a integer: ");
    scanf("%d",&a);
    getchar();

    if(a > 100)
    {
        printf("%d > 100\n",a);
    }
    else if(100 == a)
    {
        printf("%d == 100\n",a);
    }
    else if(a < 100)
    {
        printf("%d < 100\n",a);
    }


    return 0;
}

