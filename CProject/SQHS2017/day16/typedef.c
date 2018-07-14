#include<stdio.h>

typedef struct person
{
    int age;
    char name[32];
}PER;

typedef struct person STR_PER;
#define  PERSON struct person

int main(void)
{
    //struct person boy;
    STR_PER boy = {23, "HELLO"};
    printf("%d--%s\n", boy.age, boy.name);

    PER *p = &boy;
    printf("%d--%s\n", p->age, p->name);

    PERSON girl = {22, "lily"};
    printf("%d--%s\n", girl.age, girl.name);
    return 0;
}


