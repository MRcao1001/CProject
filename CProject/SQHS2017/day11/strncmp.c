#include<stdio.h>
#include<string.h>

int main(void)
{
    char arr[16] = "ABCDE";
    char buf[16] = "EDCBA";
    char str[16] = "ABCde";

    int ret = 0;
    ret = strncmp(arr, buf, 3);
    printf("ret1 = %d\n", ret);

    ret = strncmp(arr, str, 3);
    printf("ret2 = %d\n", ret);
    
    ret = strncmp(buf, arr, 3);
    printf("ret3 = %d\n", ret);

    return 0;
}







