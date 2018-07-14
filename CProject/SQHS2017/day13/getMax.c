#include<stdio.h>

int getMax(int a, int b)
{
    int max = 0;
    if(a > b)
        max = a;
        //return a;
    else
        max = b;
        //return b;
    return max;
}

int get_max(int a, int b)
{
    return (a>b?a:b);
}

int main(void)
{
    int x = 0;
    int y = 0;
    
    printf("input two integer: ");
    scanf("%d%d", &x, &y);

    //printf("%d\n", getMax(x,y));
    printf("%d\n", get_max(x,y));


    return 0;
}
