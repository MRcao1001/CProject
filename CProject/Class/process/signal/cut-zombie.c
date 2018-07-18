#include "../public.h"
#include <signal.h>

void handle(int sig)
{
    if(SIGCHLD == sig){
        wait(NULL);
        printf("parent handle child\n");
    }
}

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
    }
    if (pid == 0)
    {
        int num = 5;
        while(num){
            printf("c...%d\n",num--);
            sleep(1);
        }
        printf("c is exit\n");
    }
    else if (pid > 0)
    {
        signal(SIGCHLD,handle);
        while(1){
            printf("p...\n");
            sleep(1);
        }
    }
    return 0;
}
