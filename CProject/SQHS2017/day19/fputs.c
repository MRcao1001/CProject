#include<stdio.h>

int main(void)
{
    FILE *fpw = fopen("2.txt", "w");
    if(NULL == fpw)
        return -1;

    char caBuf[32] = "";

    printf("input string: ");
    fgets(caBuf, 32, stdin);
    
    fputs(caBuf, fpw);

    fclose(fpw);
    return 0;
}






