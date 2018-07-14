#include<stdio.h>

int main(void)
{
    char arr[16] = "hello, ";
    char buf[16] = "China!";
    char str[16] = "";

    char *pa = arr;
    char *pf = buf;
    char *ps = str;

    while(*pa != '\0')
    {
        *ps = *pa;
        ps++;
        pa++;
    }
    
    while(*pf != '\0')
    {
        *ps = *pf;
        ps++;
        pf++;
    }
    *ps = '\0';

    ps = str;
    printf("str = %s\n", str);
    printf("ps  = %s\n", ps);
    return 0;
}






