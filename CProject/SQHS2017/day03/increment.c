#include<stdio.h>

int main(void)
{
    int iNum = 4;

/*
    int a = ++iNum;
    int b = iNum++;
 */
/*
    int b = iNum++;
    int a = ++iNum;
 */

    int b = iNum++;
    int a = iNum++;

    printf("%d--%d--%d\n",iNum, a, b);

    return 0;
}

