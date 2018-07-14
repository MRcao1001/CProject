#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid = fork();
	if (pid > 0)  //A
	{
		wait(NULL);
		while (1)
		{
			printf("this is parent, pid=%d\n", getpid());
			sleep(1);
		}
	}
	else if (0 == pid)  //B
	{
		pid_t pidd = fork();
		if (0 == pidd)  //c
		{	
			int i = 10;
			while (i)
			{
				printf("child, pid=%d --> %d\n", getpid(), i);
				i--;
				sleep(1);
			}
		}
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	return 0;
}
