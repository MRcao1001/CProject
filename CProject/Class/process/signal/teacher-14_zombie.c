#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../public.h"
typedef void (*sighandler_t)(int);

void handle(int sig)
{
	if (SIGCHLD == sig)
	{
		wait(NULL);
		printf("parent handle child\n");	
	}
}

int main(void)
{
	pid_t pid = fork();
	if (pid > 0) //parent
	{
		signal(SIGCHLD, handle);
		while (1)
		{
			printf("this is parent...\n");
			sleep(1);
		}
	}
	else if (0 == pid) //child
	{
		int iNum = 5;
		while (iNum)
		{
			printf("child: time --> %d\n", iNum--);
			sleep(1);
		}	
		printf("child exit...\n");
	}
	else
	{
		perror("fork");
	}

	return 0;
}




