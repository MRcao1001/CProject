/*题目：一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如6=1＋2＋3.编程 
      　　　找出1000以内的所有完数。 */
#include <stdio.h>


int main(int argc, char const *argv[])
{
    int num =0 ;
    for(int i = 0; i < 1000; i ++){
        for(int j = 1; j < i;j++){
            (i%j==0)?(num+=j):(num+=0);
        }
        (num == i)?(printf("%d是完数\n",i)):(num = 0);
        num = 0;
    }
    return 0;
}
