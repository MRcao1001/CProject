#include "public.h"
#include <unistd.h>

int main(int argc, char const *argv[])
{

    int pipefd[2] = {0};
    if (0 == pipe(pipefd))
    {
        pid_t pid = fork();
        if (pid > 0)
        {
            pid_t pid2 = fork();
            if (pid2 > 0)
            {
                wait(NULL);
                wait(NULL);
            }

            //---------------------------------------------------------------------------------
            else if (pid2 == 0)
            {
                char text[64] = {'\0'};
                while (1)
                {
                    printf("子进程2--请输入：");
                    scanf("%s", text);
                    write(pipefd[1], text, strlen(text));
                    printf("进程2在等待...\n");
                    sleep(1);
                    memset(text, 0, 64);
                    read(pipefd[0], text, 64);
                    printf("\n子进程2--获取到：%s\n", text);
                }
            }
            //---------------------------------------------------------------------------------

            else
            {
                perror("fork2");
            }
        }

        //----------------------------------------------------------------------------------
        else if (pid == 0)
        {
            char text[64] = {'\0'};
            while (1)
            {
                memset(text, 0, 64);
                read(pipefd[0], text, 64);
                printf("\n子进程1--获取到：%s\n", text);
                printf("子进程1--请输入：");
                scanf("%s", text);
                write(pipefd[1], text, strlen(text));
                printf("进程1在等待...\n");
                sleep(1);
            }
        }
        //-----------------------------------------------------------------------------------

        else
        {
            perror("fork1");
        }
    }
    return 0;
}
