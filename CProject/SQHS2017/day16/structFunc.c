#include<stdio.h>
#include<string.h>
struct person
{
    char name[32];
    int age;
};

//传递具体的某一个成员
int value(int age)
{
    return age+=5;
}

//传递结构
struct person structValue(struct person boy)
{
    printf("%s--%d\n", boy.name, boy.age);
    return boy;
}

//传递指针
int structPointer(struct person *pPer)
{
    pPer->age = 5000;
    strcpy(pPer->name, "CHINA");
    return 0;
}

int main(void)
{
    struct person boy = {"YY", 12};
    printf("%s--%d\n", boy.name, boy.age);

    //传递具体的某一个成员
    boy.age = value(boy.age);
    printf("%d\n", boy.age);

    //传递整个结构
    structValue(boy);

    //传递结构指针
    structPointer(&boy);
    printf("%s--%d\n", boy.name, boy.age);

    return 0;
}
