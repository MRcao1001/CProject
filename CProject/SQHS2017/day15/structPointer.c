#include<stdio.h>
#include<string.h>

struct person
{
    int age;
    char name[32];
};

int main(void)
{
    struct person *ps;
    struct person stu;
    ps = &stu;

    strcpy(ps->name, "Java");
    ps->age = 23;

    printf("%d--%s\n", ps->age, ps->name);
    printf("%d--%s\n", (*ps).age,(*ps).name);

    return 0;
}

