#include<stdio.h>

int main(void)
{
    char ch = 0;

    printf("input a character: ");
    scanf("%c", &ch);
    getchar();

    switch(ch)
    {
        case 'A':
            if(ch < 'Z')
                printf("ch = %c\n",ch);
            break;
        case 'a':
        {
            int a = 2;
            printf("ch+a = %c\n",ch+a);
            a++;
            break;
        }
        default:
            printf("error\n");
            break;
    }

    //printf("a = %d\n", a); //error
    return 0;
}


