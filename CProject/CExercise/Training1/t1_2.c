#include <stdio.h>


int main(int argc, char const *argv[])
{
    int n=0;
    printf("请输入总人数");
    scanf("%d",&n);
    getchar();
    int arr[n];
    //定义一个数来记录当前数到几
    int temp =1;
    for(int i=1;i<=n;i++){
        arr[i-1] = i;
    }

    //当幸存者大于一位时就得继续屠杀
    while(n>1){
        for(int i =0;i < n ;i++){
            
            if(temp==3){
                //当数到三时将数组元素前移一位
                printf("淘汰了：%d号\n",arr[i]);
                for(int j = i; j < n; j++){
                    arr[j] = arr[j+1];
                }
                n--;
                //数到三之后就要重一开始重新数
                temp =1;
                i--;
                continue;
                //数组最后一个元素被遗弃，幸存者数量减一,数组变短一位
                
            }
            //me没有数到三就接着数
            temp++;
        }
        //第一轮数完，判断幸存者，大于一继续淘汰
    }

   
    printf("经过残酷的斗争，幸存者是：%d号 ",arr[0]);
   
    printf("\n");
    return 0;
}
