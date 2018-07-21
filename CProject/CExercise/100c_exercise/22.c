/*程序22】 
      题目：两个乒乓球队进行比赛，各出三人。甲队为a,b,c三人，乙队为x,y,z三人。已抽签决定 
      　　　比赛名单。有人向队员打听比赛的名单。a说他不和x比，c说他不和x,z比，请编程序找出 
      　　　三队赛手的名单。  */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char m[3] = {'x', 'y', 'z'};
    char a, b, c;
    for (int i = 0; i < 3; i++)
    {
        if (m[i] != 'x' && m[i] != 'z')
        {
            c = m[i];
            m[i] = 0;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (m[i] != 'x' && m[i] != 0)
        {
            a = m[i];
            m[i] = 0;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (m[i] != 0)
        {
            b = m[i];
        }
    }
    printf("a->%c\nb->%c\nc->%c\n",a,b,c);
    return 0;
}
