#include <stdio.h>

void myprint(float num[5]){
    for(int i = 0; i < 5; i ++){
        printf("%.1f   ",num[i]);
    } 
    printf("\n");   
}

int main(int argc, char const *argv[])
{
    float num[5];
    for(int i = 0 ; i < 5 ; i ++){
        printf("请输入一个数字：");
        scanf("%f",&num[i]);
        printf("\n");
    }
    
    myprint(num);
    for(int i = 0 ; i < 5-1; i ++){
        for(int j = 0; j < 5-i-1; j ++){
            if(num[j]>num[j+1]){
                float temp = num[j];
                num[j] = num[i+1];
                num[i+1] =temp;
            }
        }
    }
    myprint(num);
    return 0;
}
