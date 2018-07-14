#include<stdio.h>
#include<string.h>

int main(void)
{
    FILE *fp = fopen("1.txt", "w+");
    if(NULL == fp)
    {
        perror("fopen error");
        return -1;
    }
#if 0
    int a = 0;
    printf("input a integer: ");
    scanf("%d", &a);
    fwrite(&a, sizeof(a), 1, fp);
#endif
#if 1
    char caBuf[32] = "";
    printf("input a string: ");
    scanf("%s", caBuf);
    fwrite(caBuf, sizeof(caBuf), 1, fp);
#endif
    puts("write OK");
    rewind(fp);
#if 0
    int ret = 0;
    fread(&ret, sizeof(ret), 1, fp);
    printf("ret = %d\n", ret);
#endif
#if 1
    memset(caBuf, '\0', sizeof(caBuf));
    fread(caBuf, sizeof(caBuf), 1, fp);
    puts(caBuf);
#endif
    fclose(fp);
    return 0;
}








