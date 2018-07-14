#include<stdio.h>
#include<string.h>

#define LEN 16

int main(void)
{
    char buf[LEN] = "HELYYYYYYY";
    char arr[LEN] = "jjj";
    int i = 0;

    strcpy(buf, arr);
    puts(buf);

    for(i=0; i<LEN; i++)
        printf("%c", buf[i]);
    printf("\n");
    printf("**%c**\n",'\0');

    return 0;
}
