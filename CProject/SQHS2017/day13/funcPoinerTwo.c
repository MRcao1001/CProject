#include<stdio.h>

int addSum(int x, int y)
{
    return x+y;
}

int reduce(int x, int y)
{
    return x-y;
}

//函数指针作为函数参数
int operater(int x, int y, char ch, int (*pfunc)(int a, int b))
{
    printf("%d %c %d = %d\n", x, ch, y, pfunc(x,y));
    return 0;
}
int main(void)
{
    int a = 0;
    int b = 0;
    char ch = 0;
    printf("input expression[a +/- b]: ");
    scanf("%d%c%d", &a, &ch, &b);
    switch(ch)
    {
        case '+':
            operater(a,b,ch,addSum);
            break;
        case '-':
            operater(a,b,ch,reduce);
            break;
        default:
            printf("input error!\n");
            break;
    }

    return 0;
}

