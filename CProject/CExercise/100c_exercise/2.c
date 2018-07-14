/*企业发放的奖金根据利润提成。利润(I)低于 或等于10万元时，奖金可提10%；利润高 
      　　　于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可可提 
      　　　成7.5%；20万到40万之间时，高于20万元的部分，可提成5%；40万到60万之间时高于 
      　　　40万元的部分，可提成3%；60万到100万之间时，高于60万元的部分，可提成1.5%，高于 
      　　　100万元时，超过100万元的部分按1%提成，从键盘输入当月利润I，求应发放奖金总数？ 
      1.程序分析：请利用数轴来分界，定位。注意定义时需把奖金定义成长整型。　　　　　　 
      2.程序源代码： */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    long i = 0;
    printf("请输入利润，单位（元）");
    scanf("%ld",&i);
    long j = 0;
    if(i<100000){
        printf("1--");
        j = i*0.1;
    }
    else if(i<200000 && i >100000){
        printf("2--");
        j = 10000+(i-100000)*0.75;
    }
    else if(i<400000 && i >200000){
        printf("3--");
        j = 10000 + 7500 + (i - 200000)*0.5;
    }
    else if(i<600000 && i >400000){
        printf("4--");
        j = 10000 + 7500 + 5000 + (i - 400000)*3;
    }
    else if(i<1000000 && i >600000){
        printf("5--");
        j = 10000 + 7500 + 5000 + 3000 + (i - 600000)*0.15;
    }
    else if(i > 1000000){
        printf("6--");
        j = 10000 + 7500 + 5000 + 3000 + 1500 + (i-1000000)*0.1;
    }
    else{
        printf("input error");
    }
    printf("奖金是:%ld元",j);
    return 0;
}
