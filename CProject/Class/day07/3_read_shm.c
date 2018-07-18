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
	char cSex;
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
	void *addr = shmat(shmid, NULL, SHM_RDONLY);
	if ((void*)-1 == addr)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}

	//char caMsg[64] = {'\0'};
	//strcpy(caMsg, (char*)addr);
	//memcpy(caMsg, addr, 64);
	//sscanf((char*)addr, "%s", caMsg);
	//printf("msg --> %s\n", caMsg);

	STU stu;
	memcpy(&stu, addr, sizeof(STU));
	printf("id=%d,name=%s,score=%.2f,sex=%c\n"
		   , stu.iId, stu.caName
		   , stu.fScore, stu.cSex);

	//取消和共享空间的关联
	shmdt(addr);

	return 0;
}
