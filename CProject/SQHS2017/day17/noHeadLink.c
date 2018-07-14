#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct perInfo
{
    char name[32];
    int age;
    struct perInfo *pNext;
}perInfo;

#define LEN sizeof(struct perInfo)

//定义一个全局的头指针
perInfo *pList = NULL;

perInfo *createNode()
{
    perInfo *newNode = (perInfo*)malloc(LEN);
    if(NULL == newNode)
        newNode = (perInfo*)malloc(LEN);

    newNode->pNext = NULL;
    return newNode;
}

void getData(perInfo *temp)
{
    system("clear");
    printf("input name: ");
    scanf("%s", temp->name);
    getchar();

    printf("input age: ");
    scanf("%d", &temp->age);
    getchar();

    return;
}

//无头链表的头插法
int headInsertNode()
{
    perInfo *temp = createNode();
    getData(temp);
    temp->pNext = NULL;

    //无头链表的创建
    if(NULL == pList)
        pList = temp;
    else
    {
        temp->pNext = pList;
        pList = temp;
    }
    return 0;
}

void showList()
{
    perInfo *p = pList;
    while(NULL != p)
    {
        printf("%s--%d\n", p->name, p->age);
        p = p->pNext;
    }
    return;
}

int main(void)
{
    //无头链表的头插法
    int i = 0;
    for(i=1; i<6; i++)
        headInsertNode();
    showList();


    return 0;
}

