#include <stdio.h>


int main(int argc, char const *argv[])
{
    int temp, k;
    long num[64];
    for(int i = 1 ; i <= 10000; i++){
        temp = 0;
        k = 0;
        for(int j = 1; j < i ; j ++){
            if(i%j == 0){
                temp = temp+j;
                num[k] = j;
                k++;
            }            
        }
        if(temp == i){
            printf("完数：%d，他的因子分别是：",i);
            for(int i = 0; i <k; i ++){
                printf("%ld  ",num[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
