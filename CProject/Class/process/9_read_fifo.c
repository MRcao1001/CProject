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
		perror("mkfifo");
	}	
	else
	{
		printf("make %s fifo ok\n", argv[1]);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd > 0)
	{
		char caBuf[64] = {"\n"};
		while (1)
		{
			memset(caBuf, 0, 64);
			read(fd, caBuf, 64);
			if (0 == strcmp("quit", caBuf))
			{
				break;
			}
			printf("recv msg : %s\n", caBuf);
		}
		close(fd);
	}


	return 0;
}
