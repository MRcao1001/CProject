#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(void)
{
	int iNum = 0;
	char caBuf[64] = {'\0'};

	//创建新进程
	pid_t pid = fork();
	if (-1 == pid)
	{
		perror("fork");
	}
	else if (pid > 0)
	{
		//parent
		iNum = 3;
		strcpy(caBuf, "this is parent");
		printf("parent->child pid = %d\n", pid);
	}
	else if (0 == pid)
	{
	    //child
		iNum = 10;
		strcpy(caBuf, "this is child");
		//getppid():获得父进程的进程号
		printf("child->parent pid=%d\n", getppid());
	}
	for (; iNum > 0; iNum--)
	{
		//getpid():获得子进程的进程号
		printf("%s --> pid=%d\n", caBuf, getpid());
		sleep(1);
	}

	return 0;
}
