#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>

void handle(int sig)
{
	if (SIGINT == sig)
	{
		printf("$$$$$$$$$$$$$$\n");
		int i = 10;
		while (i)
		{
			printf("handle ctrl+c...%d\n", i--);
			sleep(1);
		}
	}
	else if (SIGTSTP == sig)
	{
		printf("handle ctrl+z");
	}
	else if (SIGQUIT == sig)
	{
		printf("handle ctrl+\\");
	}
}

int main(void)
{	
	struct sigaction act;
	memset(&act, 0, sizeof(act));
	act.sa_handler = handle;

	sigemptyset(&(act.sa_mask));
	sigaddset(&(act.sa_mask), SIGTSTP);
	sigaddset(&(act.sa_mask), SIGQUIT);

	signal(SIGTSTP, handle);
	signal(SIGQUIT, handle);

	sigaction(SIGINT, &act, NULL);

	while (1)
	{
		printf("main while...\n");
		pause();
	}

	return 0;
}
