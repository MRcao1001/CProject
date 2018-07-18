/*
输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
*/
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char stream[64];
    gets(stream);
    int i  =0;
    int words =0;
    int num =0 ;
    int space = 0;
    int other = 0;
    while(stream[i] != '\0'){
        if(stream[i]>='A'&& stream[i] <='z'){
            words++;
        }
        else if(stream[i] == ' '){
            space ++;
        }
        else if(stream[i]>='0'&&stream[i]<='9'){
            num ++;
        }
        else{
            other++;
        }
        i++;
    }
    printf("字母%d个\n数字%d个\n空格%d个\n其他字符%d个\n",words,num,space,other);
    return 0;
}
