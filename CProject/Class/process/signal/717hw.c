/*
子进程。父进程模仿出租车司机，
子进程模仿顾客。ctrl+c产生SIGINT信号表示顾客拦车。
ctrl+z产生SIGTSTP信号表示司机要求顾客付钱。
ctrl+\产生SIGQUIT信号表示顾客要求停车。
*/
#include "../public.h"
#include <signal.h>

typedef void (*sighandler_t)(int);

void hey_car(int sig)
{
    if (SIGINT == sig)
    {
        printf("乘客：出租车！这里\n");
        sleep(1);
        printf("乘客您好，欢迎乘坐本公司出租车，前排乘客请系好安全带\n");
    }
}
void stop_car(int sig)
{
    if (SIGQUIT == sig)
    {
        printf("乘客：师傅麻烦停车\n");
        exit(0);
    }
}
void pay_car(int sig)
{
    if (SIGTSTP == sig)
    {
        printf("司机：先生麻烦支付车费\n");
        sleep(2);
        printf("车门已经打开\n请检查随身物品，欢迎再次乘坐\n");
        exit(0);
    }
}
int main(int argc, char const *argv[])
{
    int v = 0;
    
    int pipefd[2] = {0};
    if (0 == pipe(pipefd))
    {
        pid_t pid = fork();
         
        if (pid == 0)
        {
           
            sighandler_t prev = signal(SIGINT, hey_car);
            sighandler_t prev3 = signal(SIGTSTP, SIG_IGN);
            sighandler_t prev2 = signal(SIGQUIT, SIG_IGN);
            pause();
            signal(SIGINT, prev);
            signal(SIGQUIT, stop_car);
            while (1)
            {
                sleep(1);
                //system("clear");
                v++;
                printf("行驶了%dkm\n",v);
            }
        }
        else if (pid > 0)
        {
            sighandler_t prev = signal(SIGINT, SIG_IGN);
            sighandler_t prev2 = signal(SIGQUIT, SIG_IGN);
            sighandler_t prev3 = signal(SIGTSTP, SIG_IGN);
            printf("乘客请按ctrl c 叫车\n");
            wait(NULL);
            signal(SIGTSTP, pay_car);
            signal(SIGINT, prev);
            signal(SIGQUIT, prev2);
            printf("已经停车");
            while(1){

            }
                
            
        }
        else
        {
            perror("fork");
        }
    }

    return 0;
}
