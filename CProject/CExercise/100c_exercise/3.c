/*题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？ 
      1.程序分析：在10万以内判断，先将该数加上100后再开方，再将该数加上268后再开方，如果开方后 
      　　　　　　的结果满足如下条件，即是结果。请看具体分析： 
      2.程序源代码： */
#include<stdio.h>
#include<math.h>

double add168(double x){
    x+=168;
    
    for(double i =1;i <x; i ++){
        if(x == i*i){
            printf("%.1lf+100+168之后的平方根：%.1lf   ",x-168-100,i);
            return 1;
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    double num,result,mid;
    for(double i = 0; i < 10000; i ++){
        num = i+100;
        for(double j = 1; j < num; j ++){
            if( num == (j*j) ){
                if(add168(num)){
                    printf("%.1lf+100之后的平方根：%.1lf     ",i,j);
                    result = i;
                    printf("数字%.1lf是符合条件的数\n",i);
                    //getchar();
                    break;
                }
            }
            
        }
    }
    return 0;
}
