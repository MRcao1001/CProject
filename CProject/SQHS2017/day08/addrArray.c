#include<stdio.h>

int main(void)
{
    int arr[5];

    printf("\n    arr = %p\n", arr);
    printf("&arr[0] = %p\n", &arr[0]);
    printf("   &arr = %p\n", &arr);

    printf("\n    arr+1 = %p\n", arr+1);
    printf("&arr[0]+1 = %p\n", &arr[0]+1);
    printf("   &arr+1 = %p\n\n", &arr+1);

    printf("&arr[1] = %p\n", &arr[1]);
    printf("&arr[2] = %p\n", &arr[2]);
    printf("&arr[3] = %p\n", &arr[3]);
    printf("&arr[4] = %p\n\n", &arr[4]);
    return 0;
}


