#include<stdio.h>
#include<string.h>

struct person
{
    int age;
    char name[32];
};

int main(void)
{
    struct person boy;
    //初始化结构变量
    memset(&boy, '\0', sizeof(boy));
    //memset(&boy, 0, sizeof(boy)); //OK
    strcpy(boy.name, "CHINA");
    boy.age = 5000;

    struct person boy1 = boy;

    printf("%s--%d\n", boy.name, boy.age);
    printf("%s--%d\n", boy1.name, boy1.age);

    return 0;
}




