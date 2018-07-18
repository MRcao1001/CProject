#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle(int sig)
{
	if (SIGALRM == sig)
	{
		printf("alrm\n");
	}
}

int main(void)
{
	signal(SIGALRM, handle);
	alarm(5);
	pause();
	while(1)
	{
		printf("in main while\n");
		sleep(1);
		// do some-thing
	}

	return 0;
}
