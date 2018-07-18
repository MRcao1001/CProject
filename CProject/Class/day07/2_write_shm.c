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
	void *addr = shmat(shmid, NULL, 0);
	if ((void*)-1 == addr)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}

	//strcpy((char*)addr, "Hello World");
	//char *pMsg = "落霞与孤鹜齐飞";
	//memcpy(addr, pMsg, strlen(pMsg));
	
	//char *pMsg = "秋水共长天一色";
	//sprintf((char*)addr, "%s", pMsg);

	//STU stu = {1002, "O(∩_∩)O哈哈~", 89, 'm'};
	//memcpy(addr, &stu, sizeof(STU));

	STU *stu = (STU *)addr;
	stu->iId = 1001;
	strcpy(stu->caName, "看看撒");
	stu->fScore = 99;
	stu->cSex = 'f';

	//取消和共享空间的关联
	shmdt(addr);

	return 0;
}
