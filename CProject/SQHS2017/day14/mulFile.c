#include<stdio.h>

char * mygets(char *, int);

extern int c;

int main(void)
{
    char buf[32] = "";
    
    printf("auto.c: c = %d\n", c);

    printf("iput a string: ");
    mygets(buf, sizeof(buf));

    puts(buf);

    return 0;
}


