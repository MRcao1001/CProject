#include<stdio.h>

int main(void)
{
    FILE *fpr = fopen("note.txt", "r");
    if(NULL == fpr)
        return -1;

    char caBuf[32] = "";

    fgets(caBuf, 32, fpr);

    //puts(caBuf);
    fputs(caBuf, stdout);

    fclose(fpr);
    return 0;
}






