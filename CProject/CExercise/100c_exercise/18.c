/*求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时 
      　　　共有5个数相加)，几个数相加有键盘控制。 */
#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    int a ,num;
    int result =0;
    printf("基数是：");
    scanf("%d",&a);
    printf("几个数相加：");
    scanf("%d",&num);
    for(int i=0;i<num;i++){

            a=a*pow(10,i)+a*((i>0)?1:0);
            printf("%d\n",a);
            result = a+result;
        
    }
    printf("=%d\n",result);
    return 0;
}
