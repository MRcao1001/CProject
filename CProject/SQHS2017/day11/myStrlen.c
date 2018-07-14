#include<stdio.h>
#include<string.h>

//方法一
int myStrlen(const char *s)
{
    int i = 0;
    //下标是从 0 开始的，因此结束的时候
    //i 的值就是字符串的长度
    for(i=0; s[i]!='\0'; i++)
    ;
    return i;
}

//方法二
int my_strlen(const char *s)
{
    const char *src = s; 
    while(*src != '\0')
        src++;
    return (int)(src-s);
}

//方法三
int mystrlen(const char *s)
{
    const char *src = s; 
    printf("%p--%c**\n", s, *s);
    while(*src++)
        printf("%p--%c**\n", src, *src);
    printf("%p--%c**\n", src, *src);
    return (int)(src-s-1);
}

int main(void)
{
    char arr[64] = "";

    printf("input a string: ");
    //fgets(arr, sizeof(arr), stdin);
    gets(arr);

    printf("strlen = %ld\n", strlen(arr));
    for(int i=0; i<strlen(arr); i++)
        printf("&arr[%d] = %p--%c**\n",i, &arr[i], arr[i]);

    int len = 0;
    //len = myStrlen(arr);
    //printf("len = %d\n", len);

    //printf("len = %d\n", my_strlen(arr));
    printf("len = %d\n", mystrlen(arr));

    return 0;
}



