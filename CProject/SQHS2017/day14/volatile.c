#include<stdio.h>

int main(void)
{
    int i = 3;
    volatile int j = 3;
    
    printf("%d--%d--%d--%d\n", ++i, --i, i++, ++i);
    printf("%d--%d--%d--%d\n", ++j, --j, j++, ++j);

    return 0;
}

