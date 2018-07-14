#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//基本信息---数据
typedef struct perInfo
{
    char name[32];
    int age;
    char sex;
}perInfo;

//链表的节点结构
typedef struct perNode
{
    struct perInfo data;
    struct perNode *pNext;
}perNode;

#define NODE_LEN sizeof(struct perNode)
#define INFO_LEN sizeof(struct perInfo)

perNode *makeNode()
{
    perNode *newNode = (perNode*)malloc(NODE_LEN);
    
    if(NULL == newNode)
        newNode = (perNode *)malloc(NODE_LEN);
   
    newNode->pNext = NULL;
    return newNode;
}

void writeFile(perNode *pHead)
{
    if(NULL == pHead || NULL == pHead->pNext)
    {
        printf("no info to write!\n");
        return;
    }
    FILE *fp = fopen("person.dat", "w");
    if(NULL == fp)
    {
        perror("fopen error");
        return;
    }

    perNode *p = pHead->pNext;
    int ret = 0;
    while(NULL != p)
    {
        ret = fwrite(&p->data, INFO_LEN, 1, fp);
        if(ret < 1)
        {
            printf("write error!\n");
            break;
        }
        p = p->pNext;
    }
    
    puts("write OK ...");

    fclose(fp);
    return;
}

perNode *readFile()
{
    perNode *pHead = makeNode();
    FILE *fp = fopen("person.dat", "r");
    if(NULL == fp)
    {
        perror("fread error");
        return NULL;
    }
    
    perNode *temp = makeNode();

    while(fread(&temp->data, INFO_LEN, 1, fp) > 0)
    {
        temp->pNext = pHead->pNext;
        pHead->pNext = temp;
        temp = makeNode();  //申请新的节点
    }

    puts("read OK ...");
    fclose(fp);
    return pHead;
}


perInfo getData()
{
    system("clear");
    perInfo temp;
    memset(&temp, '\0', INFO_LEN);
    printf("姓名: ");
    scanf("%s", temp.name);
    getchar();

    printf("年龄: ");
    scanf("%d", &temp.age);
    getchar();

    printf("性别: ");
    scanf("%c", &temp.sex);
    getchar();

    return temp;
}

int headInsert(perNode *pHead)
{
    if(NULL == pHead)
    {
        perror("phead is NULL!");
        return -1;
    }

    perNode *temp = makeNode();
    temp->data = getData();

    temp->pNext = pHead->pNext;
    pHead->pNext = temp;
    temp = NULL;

    return 0;
}


void showList(perNode *pHead)
{
    if(NULL == pHead || NULL == pHead->pNext)
    {
        printf("the link is empty!\n");
        return ;
    }
    perNode *p = pHead->pNext;
    while(NULL != p)
    {
        printf("%d--%s--%c\n", p->data.age, p->data.name, p->data.sex);
        p = p->pNext;
    }

    return;
}

int main(void)
{
#if 0
    perNode *pHead = (perNode *)malloc(NODE_LEN);
    pHead->pNext = NULL;
#endif
    perNode *pHead = readFile();

#if 0
    int i = 0;
    for(i=1; i<6; i++)
        headInsert(pHead);

    writeFile(pHead);
#endif
    showList(pHead);
    return 0;
}

