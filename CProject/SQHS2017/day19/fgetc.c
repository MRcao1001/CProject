#include<stdio.h>

int main(void)
{
    FILE *fpr = fopen("./fopen.c", "r");
    if(NULL == fpr)
    {
        perror("fopen error");
        return -1;
    }

    char ch = '0';

    while((ch=fgetc(fpr)) != EOF)
        printf("%c", ch);
    puts("");

    fclose(fpr);
    return 0;
}

