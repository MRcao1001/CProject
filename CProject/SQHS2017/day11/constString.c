#include<stdio.h>

int main(void)
{
    //以下语句哪些是正确的？
    printf("%s\n", "hello,world");
    printf("%p\n", "hello,world");
    printf("%c\n", "hello,world"[0]);
    printf("%c\n", "hello,world"[0]+1);
    printf("%p\n", "hello,world"+1);

    return 0;
}

