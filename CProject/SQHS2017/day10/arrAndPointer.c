#include<stdio.h>

int main(void)
{
    int arr[5] = {1,2,3,4,5};
    int *pa = arr;

    printf("arr = %p\n", arr);
    printf("pa  = %p\n", pa);

    printf("arr+1 = %p\n", arr+1);
    printf("pa+1  = %p\n", pa+1);
    
    printf("arr+2 = %p\n", arr+2);
    printf("pa+2  = %p\n", pa+2);
    return 0;
}





