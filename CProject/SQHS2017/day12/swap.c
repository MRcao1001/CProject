#include<stdio.h>

//int x = a;
//int y = b;
void swapValue(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
    printf("swapValue:%d--%d\n", x, y);
    return;
}

//int *pa = &a;
//int *pb = &b;
int swapAddr(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
    printf("swapAddr:%d--%d\n", *pa, *pb);
    return 0;
}

int main(void)
{
    int a = 3;
    int b = 5;
    //swap(3,5);
    swapValue(a,b);
    printf("main:%d--%d\n", a, b);
    swapAddr(&a, &b);
    printf("main:%d--%d\n", a, b);
    return 0;
}
