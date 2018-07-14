#include<stdio.h>
#include<string.h>

typedef struct stu
{
    int age;
    char name[32];
}stu;

int main(void)
{
    FILE *fp = fopen("data.dat", "wb+");
    if(NULL == fp)
    {
        perror("fopen error");
        return -1;
    }

    stu boy = {5000, "China"};
    //将结构变量写入文件
    fprintf(fp, "%d--%s\n", boy.age, boy.name);

    //文件指针回到文首
    rewind(fp);

    //清空结构体内存，防止数据干扰
    memset(&boy, '\0', sizeof(boy));

    //从文件中读取结构变量的值
    fscanf(fp, "%d--%s\n", &boy.age, boy.name);

    printf("%d\n%s\n", boy.age, boy.name);

    fclose(fp);
    return 0;
}





