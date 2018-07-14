#include<stdio.h>
#include<string.h>

struct person
{
    int cGrade;
    char name[32];
};

int main(void)
{
    struct person stu[5];
    struct person *pstu = stu;
    int i = 0;
    for(i=0; i<5; i++)
    {
        pstu[i].cGrade = i + 80;
        strcpy(pstu[i].name, "hhh");
    }
    
    for(i=0; i<5; i++)
        printf("%d--%s\n", (pstu+i)->cGrade,
                           (pstu+i)->name);

    return 0;
}


