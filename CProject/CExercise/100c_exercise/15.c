/*利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示， 
      　　　60分以下的用C表示。 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char type = ' ';
    int gread = 0;
    scanf("%d", &gread);
    (gread >= 90) ? (type = 'A') : ((gread >= 60 && gread <= 89) ? (type = 'B'):(type = 'C'));
    printf("%c\n",type);
    return 0;
}
