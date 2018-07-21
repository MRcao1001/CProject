//编译加上 -ptherad
#include "../../process/public.h"

//读者写者问题分析
//一个写者写书,许多读者读书,在读者读书的时候写者不允许写书,写者写书的时候读者不允许读书
//三种分配方式:
//1:读者优先,当读者发出读书信号的时候,写者必须结束写书--enmm估计写者也写不成书了
//2:写者优先,当写者表示要写书的时候,所有读者立即停止读书
//3:公平竞争,当写者竞争到时间片之后读者立即停止读书,读者竞争到时间片之后写者立即停止写书

//创建读者信号量
sem_t reader;
//创建写者信号量
sem_t writer;
//创建是否允许读进程继续排队的信号量
sem_t quene; //值只为0或者1
//写者写文件函数
void *writeInFile(void *arg)
{
    int iNum = (int)arg;
    while (1)
    {
        //写进程检查读信号量
        //如果读信号量>0,则禁止还未开始读的读进程继续运行
        //如果读信号量=0,判断写信号量;
        //如果写信号量>0,等待写信号量变成0;
        //如果写信号=0,执行写操作;
        printf("进入写者循环\n");
        sem_post(&reader); //reader信号加一大于0,read信号=0
        sem_wait(&reader); //恢复reader信号=0

        printf("获取到了reader信号量\n");
        if (0 < &reader)
        {
            if (&quene > 0)
            {
                printf("quene信号量-1\n");
                sem_wait(&quene); //quene设置为0,因为reader信号不为0,所以当quene信号>0时需将其设为0,以免继续有读进程排队
                continue;
            }
        }
        else
        {
            printf("reader信号量=0\n");
            //判断写信号
            wait(&writer);
            if (0 == &writer)
            {
                sem_post(&writer); //加一
                printf("第%d位作者正在写入...\n", iNum);
                sleep(3);
                printf("第%d位作者写入完成...\n", iNum);
                sem_wait(&writer); //大于0则减一
                sem_post(&quene);  //quene恢复1,
                continue;
            }
            continue;
            printf("不知道发生了什么\n");
        }
    }
}
void *readFromFile(void *arg)
{
    int iNum = (int)arg;
    while (1)
    {
        //写进程检查读信号量
        //如果读信号量>0,则禁止还未开始读的读进程继续运行
        //如果读信号量=0,判断写信号量;
        //如果写信号量>0,等待写信号量变成0;
        //如果写信号=0,执行写操作;
        sem_wait(&quene);
        printf("获取到了quene信号量\n");
        if (0 < &quene)
        {
            //判断读信号
            sem_post(&reader); //读者信号量加一
            printf("第%d位读者正在读...\n", iNum);
            sleep(1);
            printf("第%d位读者读完了...\n", iNum);
            sem_wait(&reader); //读者信号量减一
            continue;
        }
        else if (&quene == 0)
        {
            continue;
        }
        else
        {
            continue;
        }
    }
}
int main(int argc, char const *argv[])
{
    //初始化没有读者的信号量
    sem_init(&reader, 0, 0);
    //初始化没有写者的信号量
    sem_init(&writer, 0, 0);
    sem_init(&quene, 0, 0);

    //创建写者线程
    pthread_t writer[3];
    for (int i = 0; i < 3; i++)
    {
        printf("创建一个写者循环\n");
        pthread_create(writer, NULL, writeInFile, (void *)i);
    }

    //创建读者线程
    pthread_t reader[10];
    for (int i = 0; i < 10; i++)
    {
        pthread_create(reader, NULL, readFromFile, (void *)i);
    }

    //主线程操作
    while (1)
    {
        pause();
    }
    return 0;
}
