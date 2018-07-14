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
		DIR *dir = opendir(argv[1]);
		if (NULL == dir)
		{
			perror("opendir");
		}
		else
		{
			struct dirent *pDirent = NULL;
			while (1)
			{
				pDirent = readdir(dir);
				if (NULL == pDirent)
				{
					break;
				}
				printf("%s\t", pDirent->d_name);
				/*
				if (S_ISREG(pDirent->d_type))
				{
				
				}
				*/
			}
			putchar('\n');
			closedir(dir);
		}
	}

	return 0;
}




