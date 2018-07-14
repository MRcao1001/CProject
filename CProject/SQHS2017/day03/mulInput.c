#include<stdio.h>

int main(void)
{
    int a = 1;
    char ch = '0';;
    
    printf("input a,ch: ");
    
    scanf("%d",&a);
    getchar();  //吸收回车符 '\n'

    ch = getchar();

    printf("a = %d\n",a);
    printf("ch = **%c**\n",ch);
    return 0;
}
