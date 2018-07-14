#include<stdio.h>
#include<string.h>

int main(void)
{
    FILE *fp = fopen("3.txt", "w+");
    if(NULL == fp)
    {
        perror("fopen error");
        return -1;
    }

    int a = 0;
    char caBuf[32] = "";

    printf("input a/string: ");
    scanf("%d%s", &a, caBuf);

    //写入前输出
    printf("prev: %d\t%s\n", a, caBuf);
    //格式化写入文件
    fprintf(fp, "%d--%s", a, caBuf);
    
    //将文件内部数据指针,移动到文首
    rewind(fp);

    //重新初始化,防止原有数据干扰
    a = 0;
    memset(caBuf, 0, 32);
    //注意以下读取方式的区别
    //fscanf(fp, "%d%s", &a, caBuf);
    fscanf(fp, "%d--%s", &a, caBuf);
    printf("a = %d\ncabuf:%s\n", a, caBuf);

    fclose(fp);
    return 0;
}





