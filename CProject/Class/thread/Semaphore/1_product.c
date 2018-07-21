/*
 可以将信号量理解为一个整数值
 代表可用资源的数量
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <time.h>
#include <pthread.h>

#define PRO_NUM 5    //5个生产者
#define CUS_NUM 11   //11个消费者
#define DISH_NUM 8   //8个盘子

pthread_mutex_t mutex;   //线程锁 

sem_t full_sem;    //有食物信号量
sem_t empty_sem;   //没有食物信号量

char g_caDish[DISH_NUM];   //存放食物的盘子

int g_iProNextNum = 0;     //厨师将要操作哪个盘子
void *product(void *arg)   //生产者线程函数
{
	int iNum = (int)arg;
	//产生随机因子
	srand((unsigned int)time(NULL));
	while (1)
	{
		//生产之前，首先得检查空盘子信号量的值是否>0
		//若>0表示有空盘子可供生产
		//则会自动将信号量的值减一,表示使用了一个资源
		//若=0表示所有盘子都有食物，则挂起程序等待
		//直到有消费者将其唤醒
		sem_wait(&empty_sem);

		pthread_mutex_lock(&mutex);

		g_caDish[g_iProNextNum] = rand()%24+'A';
		printf("第%d个生产者往第%d个盘子中生产了%c食物\n"
			   , iNum+1, g_iProNextNum, g_caDish[g_iProNextNum]);
		//下一次生产食物的盘子
		g_iProNextNum = (g_iProNextNum+1)%DISH_NUM;	
		
		pthread_mutex_unlock(&mutex);

		//唤醒所有等待full_sem的消费者
		//自动将full_sem值加一
		sem_post(&full_sem);

		sleep(1);
	}
	return NULL;
}

//消费者将要消费哪个盘子中的食物
int g_iCusNext = 0;
void *customer(void *arg)  //消费者线程函数
{
	int iNum = (int)arg;
	while (1)
	{
		//检查full_sem的值值否>0
		//若>0表示有食物可供消费
		//则自动将full_sem的值减一
		//若=0表示没有食物可供消费
		//则挂起等待，直到有其他线程将其唤醒
		sem_wait(&full_sem);
		
		pthread_mutex_lock(&mutex);
		
		printf("第%d个消费者吃了第%d个盘子中的%c食物\n"
			   , iNum+1, g_iCusNext
			   , g_caDish[g_iCusNext]);
		g_caDish[g_iCusNext] = '\0';
		g_iCusNext = (g_iCusNext+1)%DISH_NUM;
		
		pthread_mutex_unlock(&mutex);
		
		//唤醒所有等待empty_sem的厨师
		//并将empty_sem的值加一
		sem_post(&empty_sem);

		sleep(1);
	}

	return NULL;
}

int main(void)
{
	//清空盘子
	memset(g_caDish, 0, DISH_NUM);
	
	//初始化信号量
	sem_init(&empty_sem, 0, DISH_NUM);
	sem_init(&full_sem, 0, 0);

	//创建生产者线程
	pthread_t pro[PRO_NUM];
	int i = 0;
	for (; i<PRO_NUM; i++)
	{
		pthread_create(pro+i, NULL, product, (void*)i);
	}
	
	//创建消费者线程
	pthread_t cus[CUS_NUM];
	for (i = 0; i<CUS_NUM; i++)
	{
		pthread_create(cus+i, NULL, customer, (void*)i);
	}

	while (1)
	{
		pause();
	}

	return 0;
}

