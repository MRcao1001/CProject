/*
线程：属于创建他的进程，不和进程分离，
      该进程下创建的所有线程共享进程资源
	  也将创建线程的进程称之为主线程
	  所以线程并发运行
*/

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;

//系统最小的调度单位为线程

int g_iNum = 0;

void *fun(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		g_iNum++;
		printf("thread --> num = %d\n", g_iNum);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main(void)
{
	pthread_t thr;
	pthread_create(&thr, NULL, fun, NULL);

	while (1)
	{
		pthread_mutex_lock(&mutex);
		g_iNum++;
		printf("main --> num = %d\n", g_iNum);
		pthread_mutex_unlock(&mutex);
	}

	return 0;
}
