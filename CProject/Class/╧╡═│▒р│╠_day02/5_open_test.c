#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>   //errno
#include <string.h>  //strerror
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int i = 1;
		int fd = 0;
		for (; i<argc; i++)
		{
			fd = open(argv[i], O_RDWR);
			if (-1 == fd)
			{
				printf("open %s failed --> %s\n"
					   , argv[i], strerror(errno));
			}
			else
			{
				printf("open %s ok\n", argv[i]);
			}
		}
	}

	return 0;
}
