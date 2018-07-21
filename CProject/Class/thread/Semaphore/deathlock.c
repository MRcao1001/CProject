#include "../../process/public.h"

//定义联合体
union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *arrsy;
    struct seminfo *_buf;

};
//定义线程锁
pthread_mutex_t mutex_t;
int  semid = 0;

//拿起筷子,资源(信号量)+1
void getChopsticks(int iNum){
    int left = iNum;
    int right = (iNum+1)%5;
    struct sembuf sem[2] = {
        {left,-1,0},
        {right,-1,0}
    };
    //检查指定集合中指定位置的信号量的值是否>0__bos0
    //若大于0表示该信号量对应的值没有使用
    //则对该信号量值-1,表示使用了对应的筷子
    //若指定的两个信号量的值不同时>0,
    //则阻塞等待
    semop(semid,sem,2);

}

void putChopsticks(int iNum){
    int left = iNum;
    int right = (iNum+1)%5;
    struct sembuf sem[2] = {
        {left,1,0},
        {right,1,0}
    };
    semop(semid,sem,2);
}
void *eat(void *arg){
    int iNum = (int)arg;
    while(1){
        printf("第%d个哲学家正在思考...\n",iNum+1);
        sleep(1);
        getChopsticks(iNum);
        printf("第%d个哲学家获得筷子,开始就餐...\n",iNum+1);
        sleep(1);
        pthread_mutex_lock(&mutex_t);
        putChopsticks(iNum);
        printf("第%d个哲学家放下筷子,结束就餐...\n",iNum+1);
        pthread_mutex_unlock(&mutex_t);
        //为了防止在放下筷子之后不打印,使用线程锁将上面两个语句捆绑
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    //按照指定的权限创建一组含有5个信号量的集合
    //成功返回该集合的标识符
    //失败返回-1
    semid = semget(0x001024,5,IPC_CREAT|0664);
    if(-1 == semid){
        perror("semget");
        exit(EXIT_FAILURE);
    }
    union semun sem;
    sem.val = 1;
    int i = 0;
    for(;i<5;i++){
        //使用联合体对集合中的信号量赋值
        semctl(semid,i,SETVAL,sem);
    }

    pthread_t thr[5];
    for(i = 0; i <5; i++){
        //创建5个哲学家线程
        pthread_create(thr+i,NULL,eat,(void*)i);
    }

    while(1){
        pause();
    }
    return 0;
}
