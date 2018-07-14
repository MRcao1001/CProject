#include<stdio.h>
#include<string.h>

int main(void)
{
    char arr[16] = "Hello, China";
    char buf[16] = "";
    char str[16] = "";

    printf("buf = %s\n", buf);
    //sizeof(buf) >= strlen(arr)+1
    strcpy(buf, arr);
    printf("buf = %s\n", buf);

    strncpy(str, arr, 5);
    printf("str = %s\n", str);

    return 0;
}

