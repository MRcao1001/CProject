#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>  //mmap
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDWR);
	if (-1 == fd)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	//参数一：将文件映射到内存的哪个地方
	//NULL表示让系统自动映射到内存的合适位置
	//参数二：映射内存的大小
	//参数三：映射内存的作用,
	//读写操作必须和文件打开方式保持一致
	//参数四：设置映射内存中中修改的数据是否能够被其他映射了该文件的进程可见
	//参数五：映射的文件描述符
	//参数六：从哪里开始将文件的数据映射到内存
	void *addr = mmap(NULL, 1024
					  , PROT_READ|PROT_WRITE
					  , MAP_SHARED
					  , fd, 0);
	if (MAP_FAILED == addr)
	{
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	//将数据写入内存中
	char *data = "东方明珠，小蛮腰，大裤衩";
	strcpy((char*)addr, data);

	//解除映射
	munmap(addr, 1024);

	return 0;
}
