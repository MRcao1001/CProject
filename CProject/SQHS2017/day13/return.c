#include<stdio.h>

int getData()
{
    int iNum = 0;
    printf("input a integer: ");
    scanf("%d", &iNum);
    getchar();
    return iNum;
}


int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;

    a = getData();
    b = getData();
    c = getData();

    if(a > b && a > c)
        printf("a: %d is max ...\n", a);
    else if(b > a && b > c)
        printf("b: %d is max ...\n", b);
    else if(c > a && c > b)
        printf("c: %d is max ...\n", c);


    return 0;
}

