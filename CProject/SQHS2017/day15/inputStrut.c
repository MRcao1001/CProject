#include<stdio.h>
#include<string.h>

struct person
{
    char name[32];
    int age;
};

int main(void)
{
    struct person boy;
    //boy.name = "ffhhfh";  //error
#if 1
    printf("input name: ");
    scanf("%s", boy.name);
    printf("input age: ");
    scanf("%d", &boy.age);
#endif
    printf("boy:%s--%d\n", boy.name, boy.age);

    return 0;
}
