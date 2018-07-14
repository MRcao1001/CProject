#include<stdio.h>

struct person
{
    double c;
    short b;
    char a;
};

int main(void)
{
    printf("%ld\n", sizeof(struct person));
    return 0;
}
