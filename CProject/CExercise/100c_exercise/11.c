#include <stdio.h>

// 题目：古典问题：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月 
//       　　　后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？
// 斐波那契数列前n项和

int numOfR(int mounth){
    if(mounth == 1|| mounth == 2){
        return 1;
    }
    return numOfR(mounth-1)+numOfR(mounth-2);
}
int main(int argc, char const *argv[])
{
    printf("%d",numOfR(4));
    return 0;
}
