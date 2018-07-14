#include<stdio.h>

int main(void)
{
    FILE *fp = fopen("test.txt", "a");
    if(NULL == fp)
    {
        perror("fp NULL");
        return -1;
    }

    fputs("hello, world\n", fp);

    puts("successful!\n");

    fclose(fp);
    return 0;
}












