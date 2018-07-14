#include<stdio.h>
#include<string.h>

union per
{
    int a;
    char buf[32];
    char c;
};

int main(void)
{
    //联合体大小
    printf("sizeof(union) = %ld\n", sizeof(union per));

    union per a;
    a.a = 44;
    strcpy(a.buf, "CHINA");
    //a.c = 'Y';
    
    printf("%d\n", a.a);
    printf("%s\n", a.buf);
    //printf("%c\n", a.c);

    return 0;
}

