/* 题目：有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    float add = 2;
    float arr[64]={2,1};
    printf("%lf/%lf\n",arr[0],arr[1]);
    for(int i =2; i <40; i ++){
        arr[i] = arr[i-1]+arr[i-2];
        i++;
        arr[i]= arr[i-1]-arr[i-2];
        add += (arr[i-1]/arr[i]);
        printf("%lf/%lf    add=%lf\n",arr[i-1],arr[i],add);
    }
    printf("add = %lf\n",add);
    return 0;
}
