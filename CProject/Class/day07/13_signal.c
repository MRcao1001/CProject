#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

void handle(int sig)
{
	if (SIGINT == sig)
	{
		printf("ctrl+c pressed...\n");
	}
}

int main(void)
{
	//ctrl+c --> SIGINT
	sighandler_t prev = signal(SIGINT, handle);
	int i = 0;
	while (1)
	{
		printf("time --> %d\n", ++i);
		sleep(1);
		if (10 == i)
		{
			signal(SIGINT, SIG_DFL);
		}
	}

	return 0;
}




