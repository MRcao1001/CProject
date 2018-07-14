#include<stdio.h>
#include<string.h>

int main(void)
{
    char arr[16] = "Hello, ";
    char buf[16] = "world!";

    printf("arr: %s\n", arr);
    printf("buf: %s\n", buf);

    //sizeof(arr) >= strlen(arr)+strlen(buf)+1
    strcat(arr, buf);

    printf("arr: %s\n", arr);
    printf("buf: %s\n", buf);

    strncat(buf, arr, 5);

    printf("arr: %s\n", arr);
    printf("buf: %s\n", buf);


    return 0;
}

