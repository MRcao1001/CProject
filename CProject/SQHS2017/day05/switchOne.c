#include<stdio.h>

int main(void)
{
    int a = 1;
    printf("input a: ");
    scanf("%d",&a);
    getchar();

    switch(a)
    {
        case 1:
            printf("a+1 = %d\n", a+1);
            break;
        case 2:
            printf("a+2 = %d\n", a+2);
            break;
        case 3:
            printf("a+3 = %d\n", a+3);
            break;
        default:
            printf("input error!\n");
            break;
    }

    return 0;
}

