#include<stdio.h>

int main(void)
{
    char buf[32] = "";
    int i = 0;

    printf("input a string:\n");
    fgets(buf, 32, stdin);

    if(buf[0] != ' ')
        buf[0] -= 32;

    for(i=0; buf[i]!='\0'; i++)
    {
        if(buf[i] == ' ' && buf[i+1] != ' ')
            buf[i+1] = buf[i+1] - 32;
    }

    printf("buf: %s\n", buf);
    return 0;
}


