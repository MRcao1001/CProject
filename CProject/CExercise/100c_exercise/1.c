/*
    题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num[4] = {1,2,3,4};
    int ret = 0;
    for(int i =1 ; i <= 4; i ++){
        for(int j = 1; j <= 4; j ++){
            if(j == i){
                continue;
            }
            else{
                for(int k = 1; k <= 4; k ++){
                    if(k == i || k == j){
                        continue;
                    }
                    else{
                        printf("%d%d%d\t",i,j,k);
                        ret ++;
                        if(ret%4 == 0){
                            printf("\n");
                        }
                    }
                }
            }
            
        }
    }
    printf("一共有%d个",ret);
    return 0;
}
