#include<stdio.h>

int main(void)
{
    //采用科学计数法表示实型数据
    float fNum = 3.14e-2;
    //e后的数字必须为整数
    //float fNumOne = 3.14e2.2;     //error
    float fNumTwo = 23E2;
    printf("%f\n",fNum);
    //printf("%f\n",fNumOne);
    printf("%f\n",fNumTwo);
    return 0;
}

