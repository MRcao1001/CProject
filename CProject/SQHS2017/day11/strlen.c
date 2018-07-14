#include<stdio.h>
#include<string.h>

int main(void)
{
    char arr[16] = "Hello";
    char *pa = arr;

    char buf[16] = "";
    fgets(buf, sizeof(buf), stdin);
    printf("%ld\n", strlen(buf));       
    

    printf("%ld\n", strlen("Hello"));   //5
    printf("%ld\n", strlen(arr));       //5
    printf("%ld\n", strlen(pa));        //5

    printf("%ld\n", sizeof("Hello"));   //6
    printf("%ld\n", sizeof(arr));       //16
    printf("%ld\n", sizeof(pa));        //8

    return 0;
}






