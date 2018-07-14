#include<stdio.h>

int main(void)
{
    int arr[5] = {1,2,3,4,5};
    int  *pa = arr;

    pa++;
    printf("*pa = %d\n", *pa);

    pa = &arr[3];

    pa--;
    printf("*pa = %d\n", *pa);


    return 0;
}







