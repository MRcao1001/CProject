/*************************************************************************
    > File Name: 4.c
    > Author: mrcao
    > Mail: 1805448051@qq.com 
    > Created Time: Fri 13 Jul 2018 10:16:03 AM CST
    【程序4】 
      题目：输入某年某月某日，判断这一天是这一年的第几天？ 
      1.程序分析：以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，特殊 
      　　　　　　情况，闰年且输入月份大于3时需考虑多加一天。
      2.程序源代码：
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char const *argv[])
{
    int year,mounth,day; 
    printf("请输入年：");
    scanf("%d",&year);
    getchar();
    printf("请输入月：");
    scanf("%d",&mounth);
    getchar();
    printf("请输入日：");
    scanf("%d",&day);
    getchar();

    if(year%400 == 0){
        if(mounth>=1 && mounth<=12){
            switch(mounth){
                case 1:{
                    
                }
                case 2:{

                }
                case 3:{

                }
                case 4:{

                }
            }
        }
    }
    return 0;
}
