#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

pid_t pid = -1;

void driver(int sig)
{
	if (SIGINT == sig)
	{
		printf("乘客拦车...\n");
		sleep(1);
		printf("司机停车，乘客上车...\n");
		sleep(1);
	}
	else if (SIGQUIT == sig)
	{
		printf("乘客要求下车...\n");
		sleep(1);
		printf("司机停车，乘客下车...\n");
		sleep(1);
	}
}

void passenger(int sig)
{
	if (SIGTSTP == sig)
	{
		printf("司机收车钱，乘客付车费...\n");
		sleep(1);
	}
}

int main(void)
{
	pid = fork();
	if (pid > 0)
	{
		//司机处理乘客的拦车信号 --> SIGINT  --> "ctrl+c" 产生
		//司机处理乘客下车信号   --> SIGQUIT --> "ctrl+\" 产生
		signal(SIGINT, driver);	
		signal(SIGQUIT, driver);
		//司机忽略收钱信号
		signal(SIGTSTP, SIG_IGN);	
		while (1)
		{
			printf("司机开车行驶中...\n");
			//挂起程序
			pause();
		}
	}
	else if (0 == pid)
	{
		//乘客处理司机结账信号  --> SIGTSTP  --> "ctrl+z" 产生
		signal(SIGTSTP, passenger);
		//乘客忽略拦车信号
		signal(SIGINT, SIG_IGN);
		//乘客忽略下车信号
		signal(SIGQUIT, SIG_IGN);
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
