#include<stdio.h>

int main(void)
{
    char buf[8] = "安";

    int i = 0;
    for(i=0; i<8; i++)
        printf("%c\n", buf[i]);



    return 0;
}

