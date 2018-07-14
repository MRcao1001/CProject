#include<stdio.h>

int main(void)
{
	//32 BitOS: %d
	//64 BitOS: %ld
    //基本数据类型所占字节数
    printf("sizeof(char)   = %ld\n", sizeof(char));
    printf("sizeof(short)  = %ld\n", sizeof(short));
    printf("sizeof(int)    = %ld\n", sizeof(int));
    printf("sizeof(long)   = %ld\n", sizeof(long));
    printf("sizeof(float)  = %ld\n", sizeof(float));
    printf("sizeof(double) = %ld\n", sizeof(double));
    //对应类型变量所占字节数
    char ch;
    int iInt;
    short sInt;
    long lInt;
    float fNum;
    double dNum;
    printf("sizeof(ch)   = %ld\n", sizeof(ch));
    printf("sizeof(sInt) = %ld\n", sizeof(sInt));
    printf("sizeof(iInt) = %ld\n", sizeof(iInt));
    printf("sizeof(lInt) = %ld\n", sizeof(lInt));
    printf("sizeof(fNum) = %ld\n", sizeof(fNum));
    printf("sizeof(dNum) = %ld\n", sizeof(dNum));
    return 0;
}



