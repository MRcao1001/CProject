/* 题目：一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在 
      　　　第10次落地时，共经过多少米？第10次反弹多高？ */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i =1;
    float height = 100;
    float s = 0;
    while(i<=15){
        s+=height;
        printf("第%d次下落的距离:%lf---已经经过距离%lf<<<->>>",i,height,s);
        height/=2;
        s+=height;
        printf("第%d次弹起的距离:%lf---已经经过距离%lf\n",i,height,s);
        i++;
    }
    return 0;
}
