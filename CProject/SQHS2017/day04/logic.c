#include<stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    printf("input a,b: ");
    scanf("%d,%d", &a, &b);
    getchar();

    int ret = ((a > 66) && (b < 66));

    printf("ret = %d\n",ret);

    printf("%d\n",(-1&&23));

    return 0;
}

