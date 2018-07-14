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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int howday(int year, int mounth, int day, int type)
{
    int arr[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int num = 0;
    printf("闰年");
    for (int i = 0; i + 1 < mounth; i++)
    {
        if (i == 1 && type == 2)
        {
            printf("平年");
            arr[i]--;
        }
        num += arr[i];
    }
    return (num + day);
}

int main(int argc, char const *argv[])
{
    int year, mounth, day, type = 2;
    while (1)
    {
        printf("请输入年：");
        scanf("%d", &year);
        printf("请输入月：");
        scanf("%d", &mounth);
        printf("请输入日：");
        scanf("%d", &day);

        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            type = 1;
        }
        printf("%d年%d月%d日是%d年的第%d天\n", year, mounth, day, year, howday(year, mounth, day, type));
    }
    return 0;
}
