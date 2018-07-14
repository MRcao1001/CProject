#include<stdio.h>
#include<ctype.h>

int main(void)
{
    char ch = '\0';

    printf("input a char: ");
    scanf("%c", &ch);

    printf("%c 的大写: %c\n", ch, toupper(ch));
    printf("%c 的小写: %c\n", ch, tolower(ch));



    return 0;
}
