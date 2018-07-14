#include<stdio.h>

#define OUT printf("HELLO\n");
#define OUTPUT printf("CHINA\n")

#define INIT_STRING "\0"

int main(void)
{
    char buf[32] = "";
    char arr[32] = INIT_STRING;
    OUT;
    OUTPUT;
    
    #undef OUT      //取消宏定义: OUT
    OUT;

    return 0;
}

