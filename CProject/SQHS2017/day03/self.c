#include<stdio.h>

int main(void)
{
    int a = 4;

    //4,6,6,6
    //5,6,5,6
    printf("%d--%d--%d--%d\n",a++,++a,a--,++a);
/*
    printf("%d--",a++); //4
    printf("%d--",++a); //6
    printf("%d--",a--); //6
    printf("%d\n",++a); //6
*/
    return 0;
}
