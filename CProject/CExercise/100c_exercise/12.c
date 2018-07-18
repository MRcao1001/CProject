/*判断101-200之间有多少个素数，并输出所有素数。 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 int main(int argc,const char *argv[]){
     int num = 0;
    for(int i =101;i <200;i++){
        for(int j = 2;j<=i;j++){
            if(i%j == 0 && i!=j){
                //printf("%d--%d\n",i,j);
                break;
            }
            else if(i == j){
                printf("%d",i);
                printf("是素数 ");
                num ++;
                break;
            }
            
        }
        //sleep(1);
    }
    printf("有素数%d个\n",num);
    return 0;
 }