#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void handle(int sig)
{
	if (SIGINT == sig)
	{
		sigset_t set;
		sigset_t old;
		sigemptyset(&set);
		sigaddset(&set, SIGTSTP);
		sigaddset(&set, SIGQUIT);
		//sigprocmask(SIG_BLOCK, &set, NULL);
		sigprocmask(SIG_BLOCK, &set, &old);
		printf("$$$$$$$$$$$$$$$$$$\n");
		int i = 20;
		while (i)
		{
			printf("ctrl + c pressed...%d\n",i--);
			sleep(1);
			if (10 == i)
			{
				//sigprocmask(SIG_UNBLOCK, &set, NULL);
				sigprocmask(SIG_SETMASK, &old, NULL);
			}
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
