#include<stdio.h>

int main(void)
{
    float fNum = 0;

    printf("input a floatNumber: ");
    scanf("%f",&fNum);

    switch(fNum)
    {
        case 3.14:
            printf("3.14 ...\n");
            break;
        case 0.618:
            printf("0.618 ...\n");
            break;
        default:
            printf("input error!\n");
            break;
    }


    return 0;
}

