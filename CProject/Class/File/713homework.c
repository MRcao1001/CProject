/*作业一：写代码完成多级目录的创建
作业二：写代码实现目录的拷贝(需要考虑子目录的情况)
*/
#include "public.h"

void cpdir(char fileName[32]){
    DIR *dir = opendir(fileName);
    if(dir == NULL){
        perror("opendir");
    }
    else{
        struct dirent *pDirent = NULL;
        while(1){
            pDirent = readdir(dir);
            if(NULL == pDirent){
                break;
            }
            //排除当前目录“.”和上级目录“..”
            if(strcmp(pDirent->d_name,".")!=0 && strcmp(pDirent->d_name,"..")){
                printf("%s\t",pDirent->d_name);
                //如果字符串不是.和.. 那么就把父文件夹和字符串拼接，形成文件夹路径递归检索
                char arr[32]={};
                strcat(arr,fileName);
                strcat(arr,"/");
                strcat(arr,pDirent->d_name);
                //递归传入拼接的字符串
                cpdir(arr);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /*--------------------------------------将从终端键入的值赋值给数组，并记录数组长度------------------------------------------------------------*/
    int i = 0;
    char myargv[32];
    for(i = 0 ; i < 32 ; i ++){
        if(argv[1][i] == '\0'){
            if(argv[1][i-1] != '/'){
                printf("错误：创建文件夹请以 / 结尾\n");
                exit(EXIT_FAILURE);
            }
            break;
        }
        myargv[i] = argv[1][i];
    }
    /*--------------------------------------创建多级文件夹，以/为标识符，遇到/则将其暂时复制为'\0'------------------------------------------------------------*/
    /*--------------------------------------然后通过access（fileName,F_OK）来判断文件夹是否被创建------------------------------------------------------------*/


    for(int j = 0; j < i; j ++){
        if(myargv[j] == '/'){
            myargv[j] = '\0';
            if(access(myargv,F_OK)!=0){
                if(mkdir(myargv,0777) == -1){
                    perror("mkdir");
                }
            }
            myargv[j] = '/';
        }
    }


    /*--------------------------------------将刚刚创建的目录拷贝到家目录下------------------------------------------------------------*/
    //使用opendir打开最高级目录，然后使用reddir读取目录下所有目录信息

    char fileName[32];
    printf("要复制的文件夹名：");
    scanf("%s",fileName);
    getchar();
    printf("文件夹内所有的文件夹如下：\n");
    cpdir(fileName);
    printf("\n");
    return 0;
}
