#include<stdio.h>

int main(void)
{
    int a = 2;
    int b = 3;
    printf("input two number: ");
    scanf("%d%d",&a, &b);

    printf("%d>%d  = %d\n",a, b, a>b);
    printf("%d<%d  = %d\n",a, b, a<b);
    printf("%d>=%d = %d\n",a, b, a>=b);
    printf("%d<=%d = %d\n",a, b, a<=b);
    printf("%d==%d = %d\n",a, b, a==b);
    printf("%d!=%d = %d\n",a, b, a!=b);

    return 0;
}
