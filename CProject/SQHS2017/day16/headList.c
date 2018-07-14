#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct perInfo
{
    char name [32];
    int age;
    char sex;
    struct perInfo *pNext;
}perInfo;

#define SIZE sizeof(struct perInfo)

void showList(perInfo *head);
perInfo *makeNode();
int getData(perInfo *temp);
perInfo *headInsertNode(perInfo *head);

//生成新的节点
perInfo *makeNode()
{
    perInfo *newNode = (perInfo*)malloc(SIZE);
    
    if(NULL == newNode)
        newNode = (perInfo*)malloc(SIZE);
    
    newNode->pNext = NULL;
    return newNode;
}

//给结构成员赋值
int getData(perInfo *temp)
{
    system("clear");
    printf("input age: ");
    scanf("%d", &temp->age);
    getchar();

    printf("input name: ");
    scanf("%s", temp->name);
    getchar();

    printf("input sex: ");
    scanf("%c", &temp->sex);
    getchar();
    return 0;
}

//头插法:添加链表节点
perInfo *headInsertNode(perInfo *head)
{
    perInfo *temp = NULL;

    //申请空间并初始化
    temp = makeNode();
    getData(temp);
   
    //将所添加的点形成一条链
    temp->pNext = head->pNext;
    head->pNext = temp;
    //置空,防止成为野指针
    temp = NULL;    
    return head;
}

//尾插法:添加链表节点
perInfo *tailInsertNode(perInfo *head)
{
    int i = 0;
    perInfo *temp = NULL;
    perInfo *tail = head;

    for(i=1; i<6; i++)
    {
        temp = makeNode();
        getData(temp);

        tail->pNext = temp;
        temp->pNext = NULL;
        tail = temp;
    }
    temp = NULL;
    return head;
}

perInfo *tailInsert(perInfo *head)
{
    perInfo *p = head;
    perInfo *temp = NULL;

    for(p=head; NULL != p->pNext; p=p->pNext)
    ;
    
    temp = makeNode();
    getData(temp);
    p->pNext = temp;
    temp->pNext = NULL;

    return head;
}


//打印输出链的内容
void showList(perInfo *head)
{
    //从第一个有效节点开始访问
    perInfo *p = head->pNext;
    //当 p = NULL 时,说明已到最后
    while(NULL != p)
    {
        printf("%s--%d--%c\n",p->name, p->age, p->sex);
        //p 向后移动, 指向下一个有效节点
        p = p->pNext;
    }
    return;
}

int main(void)
{
    perInfo *head = (perInfo*)malloc(SIZE);
    head->pNext = NULL;     //防止成为野指针
    
    int i = 0;

#if 0
    //头插法
    for(i=1; i<6; i++)
        headInsertNode(head);
#else
    //尾插法
    //tailInsertNode(head);
    for(i=1; i<6; i++)
        tailInsert(head);
#endif
    //打印数据,看结果是否正确
    showList(head);

    return 0;
}

















