#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>   //errno
#include <string.h>  //strerror
#include <stdlib.h>
#include <unistd.h>  //write

int main(int argc, char *argv[])
{
	//写文件时，不能以只读的方式打开文件
	int fd = open("/home/mrcao/test.txt", O_WRONLY);
	if (-1 == fd)
	{
		perror("open file");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("open ok\n");

		char caBuf[64] = {'\0'};
		ssize_t ret = -1;
		while (1)
		{
			printf("请输入要写入文件的数据:\n");
			scanf("%s", caBuf);
			if (0 == strcmp("quit", caBuf))
			{
				break;
			}
			ret = write(fd, caBuf, strlen(caBuf));
			if (-1 == ret)
			{
				if (EINTR == errno)
				{
					continue;
				}
				else
				{
					perror("write");
					break;
				}
			}
			else
			{
				printf("write %ld bytes to file\n"
					   , ret);
			}
		}



		close(fd);
	}

	return 0;
}
