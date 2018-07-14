#include<stdio.h>

int main(void)
{
    int a = 0;
    int sum = 0;
    while(a < 100)
    {
        a++;
        if(a == 50)
            continue;
        sum += a;
    }
    printf("%d\n", sum);
    return 0;
}
