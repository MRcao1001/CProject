#include<stdio.h>

int main(int argc, char *argv[])
{
    //检查参数的合法性
    if(argc != 3)
    {
        printf("usage: %s file1 file2\n", argv[0]);
        return -1;
    }

    FILE *fpr = fopen(argv[1], "r");
    if(NULL == fpr)
    {
        perror("fpr NULL");
        return -2;
    }
    FILE *fpw = fopen(argv[2], "w");
    if(NULL ==fpw)
    {
        perror("fpw NULL");
        //执行到此处，说明 argv[1] 正确打开
        //因此结束前应该关闭
        fclose(fpr);
        return -3;
    }

    char ch = '0';

    while((ch=fgetc(fpr)) != EOF)
    {
        fputc(ch, fpw);
    }

    puts("copy successful!");

    fclose(fpw);
    fclose(fpr);
    return 0;
}

