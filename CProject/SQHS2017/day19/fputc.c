#include<stdio.h>

int main(void)
{
    FILE *fpw = fopen("1.txt", "w");
    if(NULL == fpw)
    {
        perror("fopen error");
        return -1;
    }

    char ch = '0';
    printf("input char: ");
    ch = getchar();

    //向文件中写入一个字符
    fputc(ch, fpw);

    fclose(fpw);
    return 0;
}






