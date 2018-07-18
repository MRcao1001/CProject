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

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGALRM);
	sigprocmask(SIG_BLOCK, &set, NULL);

	sigset_t new;
	sigemptyset(&new);
	sigaddset(&new, SIGINT);

	alarm(5);
	//1,用SIGINT和SIGALRM交换-->SIGALRM变成UNBLOCK
	//2,挂起程序
	sigsuspend(&new);
	while(1)
	{
		printf("in main while\n");
		sleep(1);
		// do some-thing
	}

	return 0;
}
