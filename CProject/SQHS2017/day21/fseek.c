#include<stdio.h>

int main(void)
{
    FILE *fp = fopen("./mygets.c", "a");
    if(NULL == fp)
    {
        perror("fopen error");
        return -1;
    }

    //fseek(fp, -10, SEEK_END);
    //fseek(fp, 10, SEEK_SET);
    
    //相当于: rewind()
    fseek(fp, 0, SEEK_SET);
    
    long ret = ftell(fp);
    printf("ret = %ld\n", ret);

    fclose(fp);
    return 0;
}



