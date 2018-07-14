#include "public.h"

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if (pid > 0)
    {
        /*---wait();等待子进程结束 -----*/
        while (1)
        {
            printf("parent process %d\n", getpid());
            sleep(1);
        }
    }
    else if (0 == pid)
    {
        int i = 10;
        while (i)
        {
            printf("\t%d son process %d\n", i,getpid());
            i--;
            sleep(1);
        }
    }
    else
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    return 0;
}
