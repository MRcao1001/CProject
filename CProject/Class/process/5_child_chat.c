#include "public.h"

int main(void)
{
	int pipefd[2] = {0};
	if (0 == pipe(pipefd))
	{
		pid_t pid = fork();
		if (pid > 0)  //parent
		{
			pid_t pid2 = fork();
			if (0 == pid2)
			{
				char caMsg[64] = {'\0'};
				char *p = "第二个子进程输入:";
				while (1)
				{
					write(STDOUT_FILENO, p, strlen(p));
					scanf("%s", caMsg);
					write(pipefd[1], caMsg, strlen(caMsg));
					if (0 == strcmp("quit", caMsg))
					{
						break;
					}
					sleep(1);
					memset(caMsg, 0, 64);
					read(pipefd[0], caMsg, 64);
					if (0 == strcmp("quit", caMsg))
					{
						break;
					}
					printf("第二个子进程获得信息:%s\n", caMsg);
				}
			}
			else if (pid2 > 0)
			{
				printf("父进程等待子进程的结束...\n");
				wait(NULL);
				wait(NULL);
				printf("父进程给所有子进程收尸完毕...\n");
			}		
		}
		else if (0 == pid)  //child
		{
			char caMsg[64] = {'\0'};
			char *p = "第一个子进程输入:";
			while (1)
			{
				memset(caMsg, 0, 64);
				//阻塞读
				read(pipefd[0], caMsg, 64);
				if (0 == strcmp("quit", caMsg))
				{
					break;
				}
				printf("第一个子进程获得信息:%s\n", caMsg);
				
				write(STDOUT_FILENO, p, strlen(p));
				scanf("%s", caMsg);
				write(pipefd[1], caMsg, strlen(caMsg));
				if (0 == strcmp("quit", caMsg))
				{
					break;
				}
				sleep(1);
			}	
		}
		else  //error
		{
			perror("fork");
		}	
	}
	else
	{
		perror("pipe");
	}

	printf("Hello World\n");

	return 0;
}
