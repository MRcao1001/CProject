#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
void *thread1(void *arg)
{
    while (1)
    {
        printf("1------------\n");
        sleep(1);
    }
}
void *thread2(void *arg)
{
    while (1)
    {
        printf("2------------\n");
        sleep(1);
    }
}
void *thread3(void *arg)
{
    while (1)
    {
        printf("3------------\n");
        sleep(1);
    }
}
int main(int argc, char const *argv[])
{
    pthread_t thr1;
    pthread_t thr2;
    pthread_t thr3;

    pthread_create(&thr1,NULL,(void *)thread1,(void *)888);
    pthread_create(&thr2,NULL,(void *)thread2,(void *)777);
    pthread_create(&thr3,NULL,(void *)thread3,(void *)666);
    while(1){
        printf("main----------\n");
        sleep(1);
    }
    
    return 0;
}
