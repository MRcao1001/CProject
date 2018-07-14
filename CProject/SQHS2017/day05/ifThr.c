#include<stdio.h>

int main(void)
{
    int a = 3;
    int b = 6;

    printf("input a,b: ");
    scanf("%d,%d",&a, &b);

    if(a > b)
    {
        int max = a;
    }
    printf("end: %d\n", max);

    return 0;
}
