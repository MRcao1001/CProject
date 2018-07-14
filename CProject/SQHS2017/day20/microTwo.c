#include<stdio.h>

#define MAX(a,b) a>b?a:b
#define MUL(a,b) ((a)*(b))


int main(void)
{
    //ret = a>b?a:b;
    int ret = MAX(4,66);
    printf("ret = %d\n", ret);

    //ret = 4*5;
    ret = MUL(4,5);
    printf("ret = %d\n", ret);

    //ret = 3+2 * 4+1;
    ret = MUL(3+2, 4+1);
    printf("ret = %d\n", ret);


    return 0;
}

