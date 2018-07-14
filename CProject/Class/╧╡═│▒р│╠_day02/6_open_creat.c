#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>   //errno
#include <string.h>  //strerror
#include <stdlib.h>
  
int main(int argc, char *argv[])
{
	//O_CREAT:若文件不存在则按照指定的访问权限创建
	int fd = open(argv[1], O_RDWR|O_CREAT, 0664);
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
