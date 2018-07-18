#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void handle(int sig)
{
	if (SIGALRM == sig)
	{
		printf("alarm ring ...\n");
	}
}

int main(void)
{
	alarm(10);
	signal(SIGALRM, handle);
	pause();
	printf("hello world\n");

	return 0;
}
