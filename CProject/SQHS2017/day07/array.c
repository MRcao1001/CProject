#include<stdio.h>

int main(void)
{
    //int arr[];    //Error
    int iArr[] = {1,2,3,4};

    int a = 5;
    //int buf[a] = {0};   //Error

    int b = 0;
    scanf("%d", &b);
    //int iBuf[b] = {0};  //Error

    const int c = 5;
    //int cbuf[c] = {0};

    return 0;
}

