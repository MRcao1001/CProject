/*题目：用*号输出字母C的图案。 
      1.程序分析：可先用'*'号在纸上写出字母C，再分行输出。 
      2.程序源代码： */
#include <stdio.h>
#include <stdlib.h>
void printwords(int size, char words[64])
{
    system("clear");
    for (int j = 0; j < size; j++)
    {
        printf("%c", words[j]);
    }
}
int main(int argc, char const *argv[])
{
    char words[3][64] = {
        {"   *\n  * *\n *   *\n*     *\n*******\n*     *\n*     *\n"},
        {"******\n*     *\n*     *\n******\n*     *\n*     *\n******\n"},
        {" ******\n*     \n*     \n*     \n*     \n*     \n*     \n ******\n"}};
    system("clear");
    while (1)
    {
        switch (getchar())
        {
        case 'a':
        {
            printwords(51, words[0]);
            break;
        }
        case 'b':
        {
            printwords(54, words[1]);
            break;
        }
        case 'c':
        {
            printwords(59, words[2]);
            break;
        }
        case 'q':
        {
            exit(0);
        }
        }
    }
    return 0;
}
