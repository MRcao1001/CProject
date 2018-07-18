#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (2 != argc)
	{
		return 0;
	}
	pid_t pid = atoi(argv[1]);
	
	int i = 0;
	while (1)
	{
		printf("time --> %d\n", i+1);
		i++;
		sleep(1);
		if (5 == i)
		{
			//SIGKILL默认处理方式是结束程序
			kill(pid, SIGKILL);
		}
	}

	return 0;
}
