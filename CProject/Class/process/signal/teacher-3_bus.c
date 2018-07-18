/*
 司机: 乘客拦车  --> SIGINT  --> ctrl+c  
       提示售票员开门  -->SIGUSR1
       接受售票员的开车提示  -->SIGUSR2

 售票员：接受司机的开门提示  -->SIGUSR1
         提示司机开车   -->SIGUSR2
 */



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
		printf("司机停车...\n");
		kill(pid, SIGUSR1);
		sleep(1);
	}
	else if (SIGUSR2 == sig)
	{
		printf("老司机启动汽车，开车中...\n");
	}
}
void sall(int sig)
{
	if (SIGUSR1 == sig)
	{
		printf("售票员打开车门...\n");
		sleep(1);
		printf("乘客买票上车...\n");
		sleep(1);
		printf("售票员关好车门...\n");
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
		printf("老司机已准备好,随时可以发车...\n");
		while (1)
		{
			pause();
		}
	}
	else if (0 == pid)
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
