#include<stdio.h>

int add(int &a, int &b){
    return a+b;
}
main(int argc, char const *argv[])
{
    /* code */
    int a =3;
    int b = 4;
    int c = 5;
    printf("%d", add(a, b));
    printf("%d", add(a, c));
    return 0;
}
