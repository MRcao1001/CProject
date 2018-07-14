#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>   //opendir

int main(int argc, char *argv[])
{
	if (2 == argc)
	{
		//测试文件是否存在
		int ret = access(argv[1], F_OK);
		if (0 == ret)
		{
			//rename(argv[1], "VeryGood");
			int fd = open(argv[1], O_RDONLY);
			if (fd > 0)
			{
				off_t fileSize = lseek(fd, 0, SEEK_END);
				printf("%s size --> %ld\n"
					   , argv[1], fileSize);
			}
			close(fd);
		}
		else
		{
			perror("access");
		}
	}

	return 0;
}




