/*
线程：属于创建他的进程，不和进程分离，
      该进程下创建的所有线程共享进程资源
	  也将创建线程的进程称之为主线程
	  所以线程并发运行
*/

#include <stdio.h>
#include <pthread.h>

typedef struct Student
{
	int iId;
	char caName[32];
	float fscore;
}STU;

void *fun(void *arg)
{
	int num = (int)arg;
	while (1)
	{
		printf("in thread while --> %d\n", num);
		sleep(1);
	}
	return NULL;
}

int main(void)
{
	//参数一：获得线程标识(名字)
	//参数二：设置线程的属性
	//NULL使用线程默认属性来创建线程
	//参数三：设置线程的执行代码
	//参数四：线程函数的实参
	pthread_t thr1;
	pthread_create(&thr1, NULL, fun, (void*)666);
	pthread_t thr2;
	pthread_create(&thr2, NULL, fun, (void*)888);

	int i = 0;
	while (1)
	{
		printf("in main while --> %d\n", ++i);
		sleep(1);
	}

	return 0;
}
