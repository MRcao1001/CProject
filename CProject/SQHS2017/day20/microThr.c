#include<stdio.h>

#define CAT(n) "hello"#n

#define MICRO(a,b) a ## b

int main(void)
{
    //将 n 转化成字符串
    printf("%s\n", CAT(12345));
    printf("%s\n", CAT(eeeee));

    //将 a,b,c 拼接到一起
    //printf("%d\n", MICRO(12,34,66));
    //printf("%s\n", MICRO("qw","er"));
    MICRO("aa","bb");
    return 0;
}


