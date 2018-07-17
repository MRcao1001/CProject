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
	void *addr = shmat(shmid, NULL, SHM_RDONLY);
	if ((void*)-1 == addr)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}

	STU stu;
	//获得第一个学生的信息
	memcpy(&stu, addr, sizeof(STU));
	printf("id=%d,name=%s,score=%.1f\n"
		   , stu.iId, stu.caName, stu.fScore);

	//获得第五个学生的信息
	memcpy(&stu, (STU*)addr+4, sizeof(STU));
	//memcpy(&stu, (char*)addr+4*sizeof(STU)
	//	   , sizeof(STU));
	printf("id=%d,name=%s,score=%.1f\n"
		   , stu.iId, stu.caName, stu.fScore);
	
	//获得第二个学生的信息
	memcpy(&stu, (STU*)addr+1, sizeof(STU));
	printf("id=%d,name=%s,score=%.1f\n"
		   , stu.iId, stu.caName, stu.fScore);

	//取消和共享空间的关联
	shmdt(addr);

	return 0;
}
