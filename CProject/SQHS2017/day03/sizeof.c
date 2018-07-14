#include<stdio.h>

int main(void)
{
    int a = 4;
    printf("%ld\n",sizeof(int));
    printf("%ld\n",sizeof(a));
    printf("%ld\n",sizeof a);
    //printf("%ld\n",sizeof int); //Error
    return 0;
}
