#include<stdio.h>

int main(void)
{
    int a = 1;
    //int b = 3;
    
    printf("input a number: ");
    scanf("%d",&a);
    getchar();

    int ret = (a ? 66 : 88);
    
    printf("%d--%d\n",a,ret);

    return 0;
}
