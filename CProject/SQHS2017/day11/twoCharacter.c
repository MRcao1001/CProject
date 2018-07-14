#include<stdio.h>

int main(void)
{
	char arr[3][8] = {"Hello","China","SQHS17"};
	char (*pArr)[8] = arr;
	char *pbuf[8] = {"January","July","August"};
	char **ppa = pbuf;

	printf("arr[1][1] = %c\n", arr[1][1]);
	printf("arr[0] = %s\n", arr[0]);
	
	printf("pbuf[0] = %s\n", pbuf[0]);
	printf("*(pbuf) = %s\n", *(pbuf));
	
	printf("*ppa = %s\n", *ppa);
	printf("*ppa+1 = %s\n", *ppa+1);
	printf("*(ppa+1) = %s\n", *(ppa+1));
	printf("%c\n", *ppa[1]);
	return 0;
}

