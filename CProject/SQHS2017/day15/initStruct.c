#include<stdio.h>
#include<string.h>

struct person
{
    char name[32];
    int age;
}a={"Jack", 23};

int main(void)
{
    struct person boy = {"Jerry", 21};
    struct person girl;
    strcpy(girl.name, "Lily");
    girl.age = 22;

    printf("a:%s--%d\n", a.name, a.age);
    printf("boy:%s--%d\n", boy.name, boy.age);
    printf("girl:%s--%d\n", girl.name, girl.age);

    return 0;
}
