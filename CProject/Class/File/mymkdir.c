/*************************************************************************
    > File Name: mymkdir.c
    > Author: mrcao
    > Mail: 1805448051@qq.com 
    > Created Time: Fri 13 Jul 2018 10:39:46 AM CST
 ************************************************************************/

#include "public.h"


int main(int argc, char const *argv[])
{
    for( int i =1; i < argc;i++){
        int ret = mkdir(argv[i],0777);
        if(-1 == ret){
            perror("mkdir");
        }
        else if (0 == ret){
            printf("make %s ok \n", argv[i]);
        }
    }
    return 0;
}

