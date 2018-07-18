/*打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位数字立方和等于该数 
      　　　本身。例如：153是一个“水仙花数”，因为153=1的三次方＋5的三次方＋3的三次方。 
      1.程序分析：利用for循环控制100-999个数，每个数分解出个位，十位，百位。 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    for(int i = 100;i < 1000; i ++){
        int num1 = i%10;
        int num2 = (i%100)/10;
        int num3 = (i%1000)/100;
        if(num1*num1*num1 + num2*num2*num2 + num3*num3*num3 == i){
            printf("%d\n",i);
        }

    }
    return 0;
}
