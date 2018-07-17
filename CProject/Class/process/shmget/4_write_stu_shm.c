#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

typedef struct Student
{
	int iId;
	char caName[32];
	float fScore;
}STU;

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

	//将共享内存关联到本进程空间
	//SHM_RDONLY:只读
	//0：读写
	//没有只写
	void *addr = shmat(shmid, NULL, 0);
	if ((void*)-1 == addr)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}

	memset(addr, 0, 4096);

	STU stu[5] = {{1001, "OPPO", 81}
	              , {1002, "MI", 82}
	              , {1003, "VIVO", 83}
	              , {1004, "HUAWEI", 84}
	              , {1005, "NOKIA", 85}};
	//memcpy(addr, stu, sizeof(stu));
#if 1
	int i = 0;
	for (; i<5; i++)
	{
		memcpy((STU*)addr+i, stu+i, sizeof(STU));
	}
#endif

	//取消和共享空间的关联
	shmdt(addr);

	return 0;
}
