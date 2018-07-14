#include<stdio.h>

int addSum(int a)
{
    int sum = 0;
    unsigned short i = 0;

    for(i=0; i<a+1; i++)
        sum += i;
    return sum;
}
int main(void)
{
    //自定函数实现求累加和
    int iNum = 0;
    printf("input a integer: ");
    scanf("%d", &iNum);
    int iSum = 0;
    iSum = addSum(iNum);
    printf("iSum = %d\n", iSum);
    printf("%d\n", addSum(iNum));
    return 0;
}
