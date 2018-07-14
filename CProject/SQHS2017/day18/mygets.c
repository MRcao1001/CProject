#include<stdio.h>

char *mygets(char *src, int size)
{ 
    char *dest = src;
    for(; dest<src+size-1; )
    {
        *dest = getchar();
        if(*src == '\n')
            continue;
        if(*dest == '\n')
            break;
        dest++;
    }
    if(*dest != '\n')
        while(getchar() != '\n');
    *dest = '\0';
    return src;
}

char *myGets(char *src, int size)
{	
	int i = 0;
	for(i=0; i<size-1; i++)
	{
		src[i] = getchar();
		if(src[0] == '\n')
			i--;
		if(src[i] == '\n')
			break;	
	}
	if(src[i] != '\n')
		while(getchar() != '\n');
	src[i] = '\0';
	return src;
}

int main(void)
{
	char buf[8] = "";
	printf("input a string: ");
	mygets(buf, 8);
	printf("buf: %s\n", buf);
	return 0;
}



