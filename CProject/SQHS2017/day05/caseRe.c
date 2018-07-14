#include<stdio.h>

int main(void)
{
    int a = 0;
    printf("input a: ");
    scanf("%d",&a);
    getchar();
    switch(a)
    {
        case 1:
            printf("Hello, ONE\n");
            break;
        /*
         //case 标签不能重复
        case 1:
            printf("ONE,Hello\n");
            break;
        */
        case '1':
            printf("hello, china!\n");
            break;
    }
    return 0;
}

