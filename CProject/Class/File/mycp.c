#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// cp src dest
int main(int argc, char *argv[])
{
	if (3 == argc)
	{
	    int srcfd = open(argv[1], O_RDONLY);
        if (-1 == srcfd)
        {
            perror("open src file");
            exit(EXIT_FAILURE);
        }
	    int destfd = open(argv[2], O_WRONLY|O_CREAT, 0664);
        if (-1 == destfd)
        {
            perror("open dest file");
            exit(EXIT_FAILURE);
        }
		ssize_t ret = -1;
		char caBuf[1024] = {'\0'};
		while (1)
		{
			memset(caBuf, 0, sizeof(caBuf));
			ret = read(srcfd, caBuf, sizeof(caBuf));
			if (ret > 0)
			{
				write(destfd, caBuf, ret);
			}
			else if (0 == ret)
			{
				break;
			}
			else 
			{
				perror("read");
				break;
			}
		}
		close(srcfd);
		close(destfd);

    }
}




