#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int shmid = shmget(0x001024, 4096
					   , IPC_CREAT|0664);
	if (-1 == shmid)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("shmid = %d\n", shmid);

	return 0;
}
