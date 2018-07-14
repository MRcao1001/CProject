#include<stdio.h>

int main(void)
{
    int a = 123456;
    printf("%3d\n",a);
    printf("%-3d\n",a);

    printf("%9d\n",a);
    printf("%-9d***\n",a);
    return 0;
}
