#include<stdio.h>

int main(void)
{
    char ch = '\0';
    printf("input a char: ");
    scanf("%c", &ch);
    getchar();
    printf("**%c**\n", ch);


    return 0;
}


