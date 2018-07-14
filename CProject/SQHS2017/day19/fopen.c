#include<stdio.h>

int main(void)
{
    //打开一个存在的文件
    FILE *fpr = fopen("./bool.c", "w");
    //打开不存在文件
    //FILE *fpr = fopen("./b.c", "w");
    if(NULL == fpr)
    {
        perror("fopen error");
        return -1;
    }
    else
    {
        puts("open successful!"); 
        fclose(fpr); 
    }
    return 0;
}






