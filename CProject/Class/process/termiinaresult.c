#include "public.h"


int main(int argc, char const *argv[])
{
    pid_t pid = -1;
    char caCmd[64] = {'\0'};
    
    while(1){
        struct passwd *pwd;
        pwd = getpwuid(getuid());
        printf("\033[36m(\033[32m(%s)\033[36m)\033[33m>\033[37m>\033[0m", pwd->pw_name);
        scanf("%s",caCmd);
        pid = fork();
        if(0 == pid){
            execle(caCmd,caCmd,NULL);//执行可执行命令
            break;
        }
    }
    return 0;
}
