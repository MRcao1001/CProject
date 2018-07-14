#include<stdio.h>

int main(void)
{
    int a = 3;
    int b = 4;

    float ret = a / b;
    float retTwo = (float)a / b;
    float retThr = a / (float)b;
    float retSix = (float)a / (float)b;

    printf("ret = %g\nretTwo = %g\nretThr = %g\n",
                        ret, retTwo, retThr);

    float retOne = b / a;
    float retFou = (float)b / a;
    float retFiv = b / (float)a;
    
    printf("retOne = %g\nretFou = %g\nretFiv = %g\n",
                        retOne, retFou, retFiv);
    return 0;
}

