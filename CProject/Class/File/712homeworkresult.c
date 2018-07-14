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
	int fd = open(argv[1], O_RDONLY);
    if (-1 == fd)
    {
        perror("open file");
    	exit(EXIT_FAILURE);
    }

	//获得文件大小
	off_t fileSize = lseek(fd, 0, SEEK_END);

	off_t offset = -1;
	printf("请输入文件放入数据的位置:\n");
	scanf("%ld", &offset);

	if (offset < 0)
	{
		offset = 0;
	}	
	else if (offset > fileSize)
	{
		offset = fileSize;
	}

	char caBuf[1024] = {'\0'};
	printf("请输入要放入的数据:\n");
	scanf("%s", caBuf);

	char caNewFile[128] = {'\0'};
	strcpy(caNewFile, "~");
	strcat(caNewFile, argv[1]);
	int destfd = open(caNewFile, O_WRONLY|O_CREAT, 0664);

	//将指定位置之前的数据拷贝到新文件中
	lseek(fd, 0, SEEK_SET);
	size_t iLefted = offset;
	ssize_t ret = 0;
	char caTmp[4096] = {'\0'};
	while (iLefted)
	{
		memset(caTmp, 0, sizeof(caTmp));
		if (iLefted > 4096)
		{
			ret = read(fd, caTmp, 4096);
		}
		else
		{
			ret = read(fd, caTmp, iLefted);
		}
		if (-1 == ret)
		{
			if (EINTR == ret)
			{
				continue;
			}
			break;
		}
		else
		{
			write(destfd, caTmp, ret);
		}
		iLefted -= ret;
	}	
	if (-1 == ret)
	{
		close(destfd);
		remove(caNewFile);
		close(fd);
		exit(EXIT_FAILURE);
	}

	//将新数据放入新文件中
	write(destfd, caBuf, strlen(caBuf));

	//将指定位置之后的数据放入新文件中
	while (1)
	{
		ret = read(fd, caTmp, 4096);
		if (-1 == ret)
		{
			if (EINTR == ret)
			{
				continue;
			}
			break;
		}
		else if (ret > 0)
		{
			write(destfd, caTmp, ret);
		}	
		else if (0 == ret)
		{
			break;
		}
	}
	if (-1 == ret)
	{
		close(destfd);
		remove(caNewFile);
		close(fd);
		exit(EXIT_FAILURE);
	}

	remove(argv[1]);
	rename(caNewFile, argv[1]);

	close(destfd);
	close(fd);

	return 0;
}



