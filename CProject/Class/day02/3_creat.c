#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>   //errno
#include <string.h>  //strerror

// ./a.out --> argv[0] /home/sq/test.html -->argv[1]
int main(int argc, char *argv[])
{
	//int fd = creat(argv[1], 0764);
	//若文件创建成功
	//则会自动的打开文件，并将文件的描述符返回
	int fd = creat(argv[1], 0777);
	if (-1 == fd)
	{
		//errno为全局的系统变量
		//用来保存最后一次系统调用发生的错误的编号
		//strerror:返回errno错误编号对应的错误信息
		printf("errno=%d --> %s\n", errno
			   , strerror(errno));
	}
	else
	{
		chmod(argv[1], 0777);

		printf("creat %s ok\n", argv[1]);
		printf("fd = %d\n", fd);

		close(fd);
	}

	return 0;
}
