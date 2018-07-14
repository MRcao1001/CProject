#include<stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    printf("input 3 intger: ");
    //scanf("%d%d%d",&a, &b, &c);
    //scanf("%d,%d,%d",&a, &b, &c);
    scanf("a=%d,b=%d,c=%d",&a, &b, &c);
    printf("a = %d\nb = %d\nc = %d\n",a, b, c);
    return 0;
}
