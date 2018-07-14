#include<stdio.h>

enum falg
{
    ADD_USER = 'a',
    DEL_USER,
    SHOW_ARRAY
};

int main(void)
{
    char a = 0;
    printf("input a: ");
    scanf("%c", &a); 
    switch(a)
    {
        case ADD_USER:
        {
            puts("ADD_USER ...");
            break;
        }
        case DEL_USER:
        {
            puts("DEL_USER");
            break;
        }
        case SHOW_ARRAY:
        {
            puts("SHOW_ARRAY ...");
            break;
        }
        default:
            printf("error\n");
            break;
    }

    return 0;
}
