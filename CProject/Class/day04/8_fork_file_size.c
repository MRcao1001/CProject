#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_WRONLY|O_CREAT, 0664);
	if (-1 == fd)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	//创建新进程
	pid_t pid = fork();
	if (-1 == pid)
	{
		perror("fork");
	}
	else if (pid > 0)
	{
		char caBuf[128] = {'\0'};
		while (1)
		{
			printf("父进程:请输入信息:\n");
			scanf("%s", caBuf);
			if (0 == strcmp("quit", caBuf))
			{
				break;
			}
			write(fd, caBuf, strlen(caBuf));
		}
	}
	else if (0 == pid)
	{
		off_t preFileSize = 0;
		off_t curFileSize = 0;
		while (1)
		{
			curFileSize = lseek(fd, 0, SEEK_END);
			if (preFileSize != curFileSize)
			{
				printf("file size --> %ld\n", curFileSize);
				preFileSize = curFileSize;
			}
			sleep(1);
		}
	}

	return 0;
}
