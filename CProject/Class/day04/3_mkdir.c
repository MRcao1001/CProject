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
	if (argc >= 2)
	{
		int ret = 0;
		int i = 0;
	   	for (i = 1; i<argc; i++)
		{
			ret = mkdir(argv[i], 0777);
			if (-1 == ret)
			{
				perror("mkdir");
			}
			else if (0 == ret)
			{
				printf("make %s ok\n", argv[i]);
			}
		}
	}

	return 0;
}




