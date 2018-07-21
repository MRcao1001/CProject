#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>   //errno
#include <string.h>  //strerror
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//O_RDONLY:只写的方式打开文件
	//O_WRONLY:只读的方式打开文件
	//O_RDWR:读写方式打开文件
	//若文件不存在，则不会自动创建文件
	int fd = open(argv[1], O_RDWR);
	if (-1 == fd)
	{
		perror("open file");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("open %s ok\n", argv[1]);
		close(fd);
	}

	return 0;
}
