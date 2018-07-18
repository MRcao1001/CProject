/*
将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。 
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = 0;
    scanf("%d",&num);
    int help = num;
    printf("%d = 1",num);
    for(int i=2;i<help;i++){
        if(num %i ==0){
            num = num/i;
            printf("*%d",i);
            i =2;
        }
    }
    printf("\n");
    return 0;
}
