#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if (-1 == mkfifo(argv[1], 0664))
	{
		if (EEXIST != errno)
		{
			perror("mkfifo 1");
			exit(EXIT_FAILURE);
		}
	}	
	
	if (-1 == mkfifo(argv[2], 0664))
	{
		if (EEXIST != errno)
		{
			perror("mkfifo 2");
			exit(EXIT_FAILURE);
		}
	}	

	pid_t pid = fork();
	if (0 == pid)
	{
	//fifo2
		int fd = open(argv[2], O_WRONLY);
		if (fd > 0)
		{
			char caBuf[64] = {'\0'};
			while (1)
			{
				printf("please input msg:\n");
				scanf("%s", caBuf);
				write(fd, caBuf, strlen(caBuf));
				if (0 == strcmp("quit", caBuf))
				{
					break;
				}
			}
			close(fd);
		}
	}
	else if (pid > 0) //child
	{
		//fifo1
		int fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			char caBuf[64] = {'\0'};
			while (1)
			{
				memset(caBuf, 0, 64);
				read(fd, caBuf, sizeof(caBuf));
				if (0 == strcmp("quit", caBuf))
				{
					break;
				}
				printf("recv msg:%s\n", caBuf);
			}
			close(fd);
		}		
	}
	else
	{
		perror("fork");
	}

	return 0;
}
