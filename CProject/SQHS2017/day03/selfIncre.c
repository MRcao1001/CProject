#include<stdio.h>

int main(void)
{
    int a = 3;
    int b = 5;
/*
    //sum = a++ + b;
    //sum = a + b;
    //a = a + 1;
    int sum = a+++b;

    //4--5--8
    printf("a = %d\nb = %d\nsum = %d\n",
            a, b, sum);
*/
    //3--6
    printf("%d--%d\n",a++, ++b);
    //4--6
    printf("%d--%d\n",a, b);

    return 0;
}

