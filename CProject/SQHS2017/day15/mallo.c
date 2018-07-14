#include<stdio.h>
#include<stdlib.h>  //malloc(),free()
#include<string.h>

struct person
{
    int age;
    char name[32];
};

int main(void)
{
    char *pa = (char*)malloc(sizeof(char)*16);
    if(NULL ==  pa)
    {
        //打印当前错误信息
        perror("malloc: ");
        return -1;
    }
    strcpy(pa, "CHINA");
    printf("pa = %s\n", pa);
    //释放 malloc 申请的空间
    //释放后的内存空间不可在对其进行操作
    //malloc 得到空间只能释放一次
    free(pa);

    struct person *ps = (struct person*)malloc(sizeof(struct person));

    ps->age = 23;
    strcpy(ps->name, "JJJJJ");

    printf("%d--%s\n", ps->age, ps->name);
    
    free(ps);

    return 0;
}
