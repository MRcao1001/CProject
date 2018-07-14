#include<stdio.h>

int main(void)
{
    char arr[32] = "";

    puts("input a string: ");
    fgets(arr, 32, stdin);
    //fputs(arr, stdout);
    printf("%s", arr);
    puts(arr);

    return 0;
}

