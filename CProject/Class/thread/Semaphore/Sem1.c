#include "../../process/public.h"
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#define PRO_NUM 5
#define CUS_NUM 11
#define DISH_NUM 8

//线程锁
pthread_mutex_t mutex; //线程锁


sem_t full_sem;  //有食物信号量
sem_t empty_sem; //没有食物信号量

char g_caDish[DISH_NUM]; //存放食物的盘子

int g_iproNextNum = 0;       //表示厨师将要操作哪个函数
void *product(void *arg) //生产者线程函数
{
    int iNum = (int)arg;
    //产生随机因子
    srand((unsigned int )time(NULL));
    while (1)
    {
        //检查空盘子empty_sem信号量是否为0
        //若大于0表示有空盘子可供生产;则会自动将信号量的值减一，表示使用了一个资源
        //若等于0表示没有空盘子，挂起程序
        sem_wait(&empty_sem);
        //生产食物的时候上锁
        pthread_mutex_lock(&mutex);
        //产生一个随机数
        g_caDish[g_iproNextNum] = rand()%24 +'A';
        printf("------第%d个生产者向第%d个盘子中生产了%c食物\n",iNum+1,g_iproNextNum,g_caDish[g_iproNextNum]);
        //下一次生产食物的盘子
        g_iproNextNum = (g_iproNextNum+1)%DISH_NUM;
        //生产完成之后解锁
        pthread_mutex_unlock(&mutex);

        //唤醒所有等待full_sem的消费者
        //自动将full的值加1
        sem_post(&full_sem);
        sleep(1);
    }
}


int g_iCusNext = 0;//消费者要消费哪个盘子的食物
void *customer(void *arg) //消费者线程函数
{
    int iNum = (int)arg;
    while(1){
        //检查full_sem的值是否为>0
        //若>0表示有食物可供消费
        //则自动将full_sem的值减一
        //若=0则表示没有食物可供消费,挂起程序
        sem_wait(&full_sem);
        pthread_mutex_lock(&mutex);
        printf("<<<<<第%d个消费者吃了第%d个盘子中的%c食物\n",iNum+1,g_iCusNext,g_caDish[g_iCusNext]);
        g_caDish[g_iCusNext]='\0';
        g_iCusNext = (g_iCusNext+1)%DISH_NUM;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty_sem);
        sleep(1);
    }
}
int main(int argc, char const *argv[])
{
    //清空盘子
    memset(g_caDish, 0, DISH_NUM);
    //初始化没有食物的信号量
    sem_init(&empty_sem,0,DISH_NUM);
    sem_init(&full_sem,0,0);
    //创建生产者线程
    pthread_t pro[PRO_NUM];
    int i = 0;
    for (; i < PRO_NUM; i++)
    {
        pthread_create(pro, NULL, product, (void*)i);
    }

    //创建消费者线程
    pthread_t cus[CUS_NUM];
    for (; i < CUS_NUM; i++)
    {
        pthread_create(pro, NULL, customer, (void*)i);
    }

    //主线程操作：防止子线程随主线程结束而结束
    while (1)
    {
        pause();
    }

    return 0;
}
