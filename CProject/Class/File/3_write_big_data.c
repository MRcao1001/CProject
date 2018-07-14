#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
#if 1
	int fd = open(argv[1], O_WRONLY);
    if (-1 == fd)
    {
        perror("open file");
    	exit(EXIT_FAILURE);
    }
#endif

	double lfbuf[999999];
	unsigned long int uiLefted = sizeof(lfbuf);
	unsigned long int uiWrited = 0;
	ssize_t ret = -1;
	while (uiLefted)
	{
		if (uiLefted > 4096)
		{
			ret = write(fd
					    , (char*)lfbuf+uiWrited
					    , 4096);
		}
		else
		{
			ret = write(fd
					    , (char*)lfbuf+uiWrited
					    , uiLefted);
		}
		if (-1 == ret)
		{
			if (EINTR == ret)
			{
				ret = 0;
				continue;
			}
			break;
		}
		uiLefted -= ret;
		uiWrited += ret;
	}

#if 0
	printf("%ld\n", sizeof(lfbuf));
	ssize_t ret = -1;	
	ret = write(fd, lfbuf, sizeof(lfbuf));
	printf("ret = %ld\n", ret);
#endif

	close(fd);

	return 0;
}




