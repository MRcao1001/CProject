#include "public.h"

int main(int argc, char const *argv[])
{
    //creat share memory
    int shmid = shmget(0x001024, 4096, IPC_CREAT | 0777);
    if (-1 == shmid)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    printf("shmid = %d\n", shmid);

    //how to use share memory
    void *addr = shmat(shmid, NULL, 0); 
    //0 means r&w，SHM_DNOLY read only，no write only；
    if ((void *)-1 == addr)
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    //read data from share memory
    char msg[64]={"\0"};
    strcpy(msg,(char*)addr);
    printf("%s\n",msg);
    //write data to share memory
    strcpy((char*)addr,"this-is-messege-00000");
    //Cancellation of association after completion of work
    shmdt(addr);
    return 0;
}
