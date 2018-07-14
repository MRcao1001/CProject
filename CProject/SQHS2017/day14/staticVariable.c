#include<stdio.h>

//6,9,12
int testStatic(int x)
{
    static int i = 3;
    i += x;
    printf("ii = %d\n", i);
    return 0;
}

//6,6,6
int test(int x)
{
    int i = 3;
    i += x;
    printf(" i = %d\n", i);
    return 0;
}

int main(void)
{
    int i = 0;
    for(i=0; i<3; i++)
    {
        testStatic(3);
        test(3);
    }

    return 0;
}


