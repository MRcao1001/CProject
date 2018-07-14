#include<stdio.h>


int main(void)
{
    FILE *fp = fopen("./mygets.c", "a");
    
    if(NULL == fp)
    {
        perror("fopen error");
        return -1;
    }

    //返回内部文件指针的位置
    long ret = ftell(fp);
    printf("ret = %ld\n", ret);


    fclose(fp);
    return 0;;
}








