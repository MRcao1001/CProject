#include<stdio.h>

int fabonacci(int fab)
{
    if(1 == fab || fab == 2)
        return 1;
    
    return (fabonacci(fab-1) + fabonacci(fab-2));
}

int main(void)
{
    int index = 0;
    printf("input a index: ");
    scanf("%d", &index);

    int ret = fabonacci(index);

    printf("%d index is %d\n", index, ret);
    return 0;
}
