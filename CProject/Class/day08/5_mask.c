#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

//默认情况下
//1,当信号A在处理过程中，收到了信号B,则会先去处理信号B,处理完信号B之后再回来接着处理信号A
//2,当信号A在处理过程中，又收到了信号A,会将新产生的信号A屏蔽掉，先处理完旧的信号A，才会去处理屏蔽掉的新的信号A.假如新的信号A出现了多次,则只会处理一次
void handle(int sig)
{
	if (SIGINT == sig)
	{
		printf("$$$$$$$$$$$$$$$$$$\n");
		int i = 10;
		while (i)
		{
			printf("ctrl + c pressed...%d\n",i--);
			sleep(1);
		}
	}
	else if (SIGTSTP == sig)
	{
		printf("ctrl + z pressed...\n");
	}
}

int main(void)
{
	signal(SIGINT, handle);	
	signal(SIGTSTP, handle);
	while (1)
	{
		printf("waitting signal...\n");
		pause();
	}

	return 0;
}
