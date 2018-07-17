#include "public.h"

int main(int argc, char const *argv[])
{
    typedef struct Student
    {
        int id;
        char name[32];
        float gread;
        char sex;

    } Stu;
    int shmid = shmget(0x002048, 4096, IPC_CREAT | 0777);
    if (-1 == shmid)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    printf("shmid-->%d\n", shmid);

    void *addr = shmat(shmid, NULL, 0);
    int num = 1;
    while (1)
    {
        system("clear");
        printf("数据已经刷新第%d次！\n",num);
        Stu stuget;
        printf("████████████████████████████\n");
        for (int i = 0; i < 5; i++)
        {
            memcpy(&stuget, (Stu *)addr + i, sizeof(stuget));
            printf("| %d | %s | %lf | %c |\n", stuget.id, stuget.name, stuget.gread, stuget.sex);
            printf("____________________________\n");
        }
        printf("████████████████████████████\n");
        num++;
        sleep(2);
        printf("请按回车键刷新...");
        getchar();
    }
    return 0;
}
