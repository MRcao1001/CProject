#include<stdio.h>
#include<string.h>


int main(void)
{
    char arr[16] = "abcde";
    char buf[16] = "edcba";
    char str[16] = "abcde";

    int ret = strcmp(arr, buf);
    printf("ret1 = %d\n", ret);     //-4

    ret = strcmp(buf, arr);
    printf("ret2 = %d\n", ret);     //4

    ret = strcmp(arr, str);
    printf("ret3 = %d\n", ret);     //0

    return 0;
}




