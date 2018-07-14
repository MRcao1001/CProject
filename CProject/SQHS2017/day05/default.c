#include<stdio.h>

int main(void)
{
    int value = 0;
    printf("input a value: ");
    scanf("%d",&value);
    switch(value)
    {
        default:
            printf("default.....\n");
            break;
        case 1:
            printf("11111\n");
            break;
        case 2:
            printf("22222\n");
            break;
    }
    return 0;
}

