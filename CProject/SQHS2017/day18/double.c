#include<stdio.h>
#include<stdlib.h>  //malloc(), free()
#include<string.h>  //strcpy()
#include<unistd.h>  //sleep()

typedef struct perInfo 
{
    struct perInfo *pPrev;
    char name[32];
    int age;
    struct perInfo *pNext;
}perInfo;

#define SIZE sizeof(struct perInfo)

char *mygets(char *dest, int size);
int headInsertNode(perInfo *pHead);
int tailInsertNode(perInfo *pHead);
int headDeleteNode(perInfo *pHead);
int tailDeleteNode(perInfo *);
perInfo *createNode();
void showList(perInfo *);
int initData(perInfo *);


char *mygets(char *src, int size)
{ 
    char *dest = src;
    for(; dest<src+size-1; )
    {
        *dest = getchar();
        if(*src == '\n')
            continue;
        if(*dest == '\n')
            break;
        dest++;
    }
    if(*dest != '\n')
        while(getchar() != '\n');
    *dest = '\0';
    return src;
}

perInfo *createNode()
{
    perInfo *newNode = (perInfo *)malloc(SIZE);
    if(NULL == newNode)
        newNode = (perInfo *)malloc(SIZE);

    newNode->pPrev = NULL;
    newNode->pNext = NULL;
    return newNode;
}

int initData(perInfo *temp)
{
    system("clear");
    printf("name: ");
    mygets(temp->name, sizeof(temp->name));

    printf("age: ");
    scanf("%d", &temp->age);
    getchar();
    return 0;
}


int headInsertNode(perInfo *pHead)
{
    if(NULL == pHead)
    {
        printf("%s:the link is empty!\n", __func__);
        return -1;
    }

    perInfo *p = pHead;
    perInfo *temp = createNode();
    initData(temp);

    //第一个节点的插入
    if(NULL == p->pNext)
    {
        p->pNext = temp;
        temp->pPrev = p;
    }
    //非第一个节点的插入
    else
    {
        //将新的节点连接到原有链表上
        temp->pNext = pHead->pNext;
        temp->pPrev = pHead;
        
        //断开原有链接,形成新的链接
        //保证链表的完整性
        pHead->pNext->pPrev = temp;
        pHead->pNext = temp;
    }
    temp = NULL;
    return 0;
}

//尾插法
int tailInsertNode(perInfo *pHead)
{
    if(NULL == pHead)
    {
        printf("%s:the link is empty!\n", __func__);
        return -1;
    }

    perInfo *temp = createNode();
    initData(temp);

    perInfo *p = pHead;
    while(NULL != p->pNext)
    {
        p = p->pNext;
    }

    p->pNext = temp;
    temp->pPrev = p;
    temp->pNext = NULL;
    return 0;
}

//头删法
int headDeleteNode(perInfo *pHead)
{
    if(NULL == pHead || pHead->pNext == NULL)
    {
        printf("%s:the link is empty!\n", __func__);
        return -1;
    }

    

    return 0;
}

void showList(perInfo *pHead)
{
    perInfo *pCur = pHead->pNext;
    perInfo *pPre = pHead;
    
    while(NULL != pCur)
    {
        printf("%s--%d\n", pCur->name, pCur->age);
        pCur = pCur->pNext;
        pPre = pPre->pNext;
    }
    puts("===================");
    while(pPre->pPrev != NULL)
    {
        printf("%s--%d\n", pPre->name, pPre->age);
        pPre = pPre->pPrev;
    }

    return;
}

int main(void)
{
    perInfo *pHead = createNode();

    int i = 0;
    for(i=1; i<6; i++)
    {
        //headInsertNode(pHead);
        tailInsertNode(pHead);
    }
    
    showList(pHead);


    return 0;
}





