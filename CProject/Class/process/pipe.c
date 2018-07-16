#include <unistd.h> //int pipe();成功返回0，失败返回-1
#include "public.h"

int main(int argc, char const *argv[])
{
    int pipefd[2] = {0}; //获取管道接口，管道的接口只能在创建时获取
    //创建无名管道，在内存中申请一块空间，提供读写接口
    if (0 == pipe(pipefd))
    {
        pid_t pid = fork();
        //父进程写入数据
        if (pid > 0)
        {
            char caMsg[64] = {'\0'};
            char *p = "父进程：";
            while (1)
            {
                write(STDOUT_FILENO, p, strlen(p));
                scanf("%s", caMsg);
                //向管道里面写入数据
                write(pipefd[1], caMsg, strlen(caMsg));
                //将数据写入管道并等待子进程获取后将子进程的消息写入管道再读取
                sleep(1);
                memset(caMsg, 0, 64);
                //阻塞读
                read(pipefd[0], caMsg, 64);
                printf("父进程收到来自子进程的消息：%s\n", caMsg);
            }
        }
        //子进程读取数据
        else if (pid == 0)
        {
            char caMsg[64] = {'\0'};
            system("gnome-terminal");
            while (1)
            {
                memset(caMsg, 0, 64);
                //阻塞读
                read(pipefd[0], caMsg, 64);
                printf("子进程收到来自父进程的消息：%s\n", caMsg);
                memset(caMsg, 0, 64);
                printf("子进程：%s", caMsg);
                scanf("%s", caMsg);
                //向管道里面写入数据
                write(pipefd[1], caMsg, strlen(caMsg));
                //将数据写入管道等待父进程读取后将父进程数据写入管道再读取
                sleep(1);
            }
        }
        else
        {
        }
    }
    else
    {
        perror("pipe");
    }

    return 0;
}
