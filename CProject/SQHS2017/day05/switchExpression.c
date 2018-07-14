#include<stdio.h>

int main(void)
{
    char ch = 0;

    printf("input a character: ");
    scanf("%c",&ch);
    getchar();

    switch(ch)
    {
        case 'l':
        case 'L':
        {
            printf("Linux ...\n");
            break;
        }
        case 'w':
        case 'W':
        {
            printf("Windows ...\n");
            break;
        }
        case 'i':
        case 'I':
        {
            printf("IOS ...\n");
            break;
        }
        default:
        {
            printf("input error!\n");
            break;
        }
    }

    return 0;
}

