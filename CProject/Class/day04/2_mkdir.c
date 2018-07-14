#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
//  ./s aa ~/bb  ../../cc
int main(int argc, char *argv[])
{
	int ret = mkdir(argv[1], 0664);
	if (-1 == ret)
	{
		perror("mkdir");
	}
	else if (0 == ret)
	{
		printf("make %s ok\n", argv[1]);
	}

	return 0;
}




