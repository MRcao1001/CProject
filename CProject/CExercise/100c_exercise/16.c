/*
输入两个正整数m和n，求其最大公约数和最小公倍数。
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i = ((m<n)?m:n); i >0;i--){
        if(m%i == 0&&n%i==0){

                printf("最大公约数是%d\n",i);
                break;

        }
    }
    int j =((m<n)?m:n);
    while(1){
        if(j%m == 0 && j %n==0){
            printf("最小公倍数是%d\n",j);
            break;
        }
        j++;
    }
    return 0;
}
