/*
 服务员:接待新顾客        --> SIGINT
        将顾客菜单给厨师  --> SIGUSR1
		接受厨师上菜提示  --> SIGUSR2
		结帐              --> SIGTSTP
		接受下班信号      --> SIGQUIT
		提示厨师下班      --> SIGALARM
		给子进程收尸      --> SIGCHLD

 厨师:接受服务员菜单做菜  --> SIGUSR1 
      提示服务员上菜      --> SIGUSR2
	  接受服务员下班提示  --> sIGALRM
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

pid_t pid = -1;

void waiter(int sig)
{
	switch (sig)
	{
	case SIGINT:
		printf("新顾客到来,服务员表示欢迎光临\n");
		sleep(1);
		printf("顾客点菜...\n");
		sleep(1);
		printf("服务员将菜单给厨师...\n");
		sleep(1);
		kill(pid, SIGUSR1);
		break;
	case SIGTSTP:
		printf("顾客结帐,服务员处理结帐操作...\n");
		sleep(1);
		printf("服务员表示欢迎下次光临...\n");
		sleep(1);
		break;
	case SIGUSR2:
		printf("厨师提示服务员上菜...\n");
		sleep(1);
		printf("服务员给顾客上菜...\n");
		break;
	case SIGQUIT:
		printf("服务员收到老板下班信号...\n");
		sleep(1);
		printf("服务员收拾下班，并提示厨师下班...\n");
		sleep(1);
		kill(pid, SIGALRM);
		break;
	case SIGCHLD:
		wait(NULL);
		printf("服务员管好门窗,繁忙的一天结束了\n");
		exit(EXIT_SUCCESS);
	}
}

void cooker(int sig)
{
	if (SIGUSR1 == sig)
	{
		printf("厨师收到服务员的菜单...\n");
		sleep(1);
		printf("厨师做菜中...\n");
		sleep(3);
		printf("菜做好了,厨师提示服务员上菜\n");
		sleep(1);
		kill(getppid(), SIGUSR2);
	}
	else if (SIGALRM == sig)
	{
		printf("厨师收到服务员的下班提示...\n");
		sleep(1);
		printf("厨师收拾厨房,拜灶神,下班...\n");
		sleep(1);
		exit(EXIT_SUCCESS);
	}
}

int main(void)
{
	pid = fork();
	if (pid > 0)
	{
		signal(SIGINT, waiter);  //新顾客
		signal(SIGUSR2, waiter); //上菜
		signal(SIGTSTP, waiter); //结帐
		signal(SIGQUIT, waiter); //下班
		signal(SIGCHLD, waiter); //收尸
		printf("新的一天,新的开始\n开门享通,万事大吉\n");
		while (1)
		{
			//挂起程序
			pause();
		}
	}
	else if (0 == pid)
	{
		signal(SIGINT, SIG_IGN); //忽略新顾客信号
		signal(SIGTSTP, SIG_IGN);//忽略结帐信号
		signal(SIGQUIT, SIG_IGN);
		signal(SIGUSR1, cooker);
		signal(SIGALRM, cooker);

		printf("灶王镇守，十里飘香\n");
		while (1)
		{
			//挂起程序
			pause();
		}	
	}
	else
	{
		perror("fork");
	}

	return 0;
}
