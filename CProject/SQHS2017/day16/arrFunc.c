#include<stdio.h>

void testOne(char arr[32])
{
    printf("%s:%ld\n", arr, sizeof(arr));
    return;
}

void testTwo(char arr[])
{
    printf("%s:%ld\n", arr, sizeof(arr));
    return;
}

void testThr(char *arr)
{
    printf("%s:%ld\n", arr, sizeof(arr));
    return;
}

int main(void)
{
    char buf[16] = "CHINA";
    testOne(buf);
    testTwo(buf);
    testThr(buf);
    return 0;
}






