#include<stdio.h>

int getSum()
{
    int a = 4;
    a += 5;
    return a;
}
/*
int *getAddr()
{
    int a = 5;
    a += 5;
    return &a;
}
*/
int *returnAddr()
{
    static int a = 8;
    a += 8;
    return &a;
}

int *returnPoin()
{
    int a = 4;
    int *pa = &a;
    return pa;  //error
}


char *returnPointer()
{
    const char *pa = "hello";
    return pa;
}

int main(void)
{
    int ret = getSum();
    printf("ret = %d\n", ret);

    int *pa = NULL;
    //pa = getAddr();   //error,不可返回局部地址
    pa = returnAddr();
    printf("*pa = %d\n", *pa);

    char *pb = returnPointer();
    printf("pb = %s\n", pb);
    
    return 0;
}
