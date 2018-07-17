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
    while (1)
    {
        Stu stuarr[5] = {};
        for(int i =0;i<5;i++){
            printf("请输入第%d个学生的学号\n",i+1);
            scanf("%d",&stuarr[i].id);
            printf("请输入第%d个学生的姓名\n",i+1);
            scanf("%s",stuarr[i].name);
            printf("请输入第%d个学生的成绩\n",i+1);
            scanf("%f",&stuarr[i].gread);
            getchar();
            printf("请输入第%d个学生的性别\n",i+1);
            stuarr[i].sex = getchar();
        }
        int shmid = shmget(0x002048, 4096, IPC_CREAT | 0777);
        if (-1 == shmid)
        {
            perror("shmget");
            exit(EXIT_FAILURE);
        }
        printf("shmid-->%d\n", shmid);

        void *addr = shmat(shmid, NULL, 0);
        memcpy(addr, stuarr, sizeof(stuarr));
        sleep(2);
        getchar();
    }

    // Stu stuget;
    // memcpy(&stuget,(Stu *)addr+0, sizeof(stuarr));
    // printf("%d--%s--%lf--%c--\n",stuget.id,stuget.name,stuget.gread,stuget.sex);
    return 0;
}
