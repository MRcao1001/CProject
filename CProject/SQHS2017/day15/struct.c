#include<stdio.h>
#include<string.h>

struct date
{
    int day;
    int month;
    int year;
};

struct person
{
    int age;
    char name[32];
    struct date birth;
};

int main(void)
{
    struct person boy = {23, "Jack",{12,2,1990}};

    printf("%d--%s--%d--%d--%d\n",
                    boy.age, boy.name,
                    boy.birth.day,
                    boy.birth.month,
                    boy.birth.year);
    return 0;
}
