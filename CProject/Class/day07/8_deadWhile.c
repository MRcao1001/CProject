#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int i = 0;
	while (1)
	{
		printf("pid=%d, time --> %d\n"
			   , getpid(), ++i);
		sleep(1);
	}

	return 0;
}
