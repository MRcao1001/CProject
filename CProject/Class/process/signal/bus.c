/*
司机售票员程序分析
司机
    接收乘客拦车提示---SIGINT
    发出请售票员开门的信号---SIGUSER1
    接收售票员已关门请开车的信号---SIGUSER2

售票员
    接收司机开门信号---SIGUSER1
    发出已关门请开车的信号---SIGUSER2

乘客拦车

*/
#include "../public.h"
#include <signal.h>

pid_t pid = -1;

void driver(int sig)
{
    if (SIGINT == sig)
    {
        printf("乘客拦车\n");
        sleep(1);
        printf("司机停车\n");
        kill(pid, SIGUSR1);
        sleep(1);
    }
    else if (SIGUSR2 == sig)
    {
        printf("请抓好扶手，前方到站...\n");//循环中需要输出切记加上'\n',否则程序不会输出，参见 文件 进程讲解
    }
}
void sall(int sig)
{
    if (SIGUSR1 == sig)
    {
        printf("售票员打开车门\n");
        sleep(1);
        printf("乘客买上车\n");
        sleep(1);
        printf("售票员关好车门\n");
        sleep(1);
        kill(getppid(), SIGUSR2);
    }
}

int main(void)
{
    pid = fork();
    if (pid > 0)
    {
        signal(SIGINT, driver);
        signal(SIGUSR2, driver);
        printf("wait...\n");
        while (1)
        {
            pause();
            
        }
    }
    else if (0==pid)
    {
        sleep(1);
        signal(SIGINT, SIG_IGN);
        signal(SIGUSR1, sall);
        kill(getppid(), SIGUSR2);
        while (1)
        {
            pause();
        }
    }
    else
    {
        perror("fork");
    }
    return 0;
}
