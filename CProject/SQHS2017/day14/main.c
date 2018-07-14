#include<stdio.h>

//命令行传入 main() 的参数问题
int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        printf("usage: %s <参数列表>\n", argv[0]);
        return -1;
    }

    int i = 0;
    if(argc > 1)
    {
        for(i=0; i<argc; i++)
        {
            printf("%d: %s\n", i, argv[i]);
        }
    }

    printf("end of main ...\n");
    return 0;
}
