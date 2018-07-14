#include<stdio.h>

enum enumType
{
    ZERO = 5,
    FIRST = 'A',
    SECOND = 99,
    THIRD
};

enum returnEnum
{
    EXITSUCCESS,
    EXITFAILURE
};


int main(void)
{
    //enum enumType b;
    //printf("%d\n", b.ZERO);   //Error

    printf("ZERO   = %d\n", ZERO);
    printf("FIRST  = %c\n", FIRST);
    printf("SECOND = %d\n", SECOND);
    printf("THIRD  = %d\n", THIRD);

    int a = 0;
    return 0;
}
