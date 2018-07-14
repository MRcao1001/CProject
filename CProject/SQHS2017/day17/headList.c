#include<stdio.h>
#include<stdlib.h>  //malloc(), free()
#include<string.h>  //strcpy(), memset()
#include<unistd.h>  //sleep()

//结构声明
typedef struct perInfo
{
    char name[32];
    char sex[8];
    int age;
    struct perInfo *pNext;
}perInfo;

//功能枚举
enum func
{
    EXIT = '0',
    ADD_NODE,
    DEL_NODE,
    MODIFY_NODE,
    LOOKUP_NODE,
    SHOW_LIST,
};

enum addEnum
{
    EXIT_ADD = '0',
    HEAD_INSERT,
    TAIL_INSERT,
    RAND_INSERT
};

perInfo *createNode();
char *mygets(char *buf, int size);
int initData(perInfo  *temp);
perInfo *headInsertNode(perInfo *pHead);
void showList(perInfo *pHead);
void addNodeUI(perInfo *pHead);
int function(perInfo *pHead);
void menu(perInfo *pHead);
perInfo *randInsert(perInfo *pHead, int index);
int getLength(perInfo *pHead);
perInfo *headDeleteNode(perInfo *pHead);
void delNodeUI(perInfo *pHead);
perInfo *randDeleteNode(perInfo *pHead,int index);
perInfo *tailDeleteNode(perInfo *pHead);
int modifyNode(perInfo *pHead, char *name);
perInfo *lookupNode(perInfo *pHead, char *name);

//宏定义结构的大小
#define SIZE sizeof(struct perInfo)

//申请内存空间,并返回(即返回一个新的节点)
perInfo *createNode()
{
    perInfo *newNode = (perInfo*)malloc(SIZE);
    
    if(NULL == newNode)
        newNode = (perInfo*)malloc(SIZE);
    
    //将新节点的指针域初始化
    newNode->pNext = NULL;
    return newNode;
}

//自定义函数实现 gets
char *mygets(char *buf, int size)
{
    char *dest = buf;
    int i = 0;
    for(i=0; i<size-1; i++, dest++)
    {
        *dest = getchar();
        if('\n' == *dest)
            break;
    }

    if(*dest != '\n')
        while(getchar() != '\n');
    *dest = '\0';
    return buf;
}

//初始化数据域
int initData(perInfo  *temp)
{
    system("clear");
    printf("姓名: ");
    mygets(temp->name, sizeof(temp->name));

    printf("性别: ");
    mygets(temp->sex, sizeof(temp->sex));

    printf("年龄: ");
    scanf("%d", &temp->age);
    getchar();
    return 0;
}

//头插法
perInfo *headInsertNode(perInfo *pHead)
{
    perInfo *temp = createNode();
    initData(temp);

    //将新节点先连到链表上
    temp->pNext  = pHead->pNext;
    //断开原有的连线,形成新的连线
    pHead->pNext = temp;

    return pHead;
}

//尾插法
perInfo *tailInsertNode(perInfo *pHead)
{
    perInfo *p = pHead;
    
    //循环遍历找到最后一个节点
    while(NULL != p->pNext)
        p = p->pNext;

    perInfo *temp = createNode();
    initData(temp);

    //将新节点插入到最后一个
    p->pNext = temp;
    //同时将新节点的 pNext 置空
    temp->pNext = NULL;
    
    return pHead;
}

//获得链表长度
int getLength(perInfo *pHead)
{
    int iLen = 0;
    perInfo *p = pHead->pNext;

    while(NULL != p)
    {
        iLen++;
        p = p->pNext;
    }

    return iLen;
}

//任意位置插入
perInfo *randInsert(perInfo *pHead, int index)
{
    int len = getLength(pHead);
    //若大于链表长度则退出
    if(index > len || index < 1)
        return pHead;
    int i = 0;
    perInfo *p = pHead;
    perInfo *temp = createNode();
    initData(temp);
    
    //找到要插入位置的前一个位置
    for(p=pHead,i=1; i<index ;p=p->pNext,i++)
    {}

    temp->pNext = p->pNext;
    p->pNext = temp;

    return pHead;
}

//销毁链表
perInfo *destroyList(perInfo *pHead)
{
    if(NULL == pHead || NULL == pHead->pNext)
    {
        printf("%s: the list is empty!\n", __func__);
        return pHead;
    }
    
    perInfo *temp = pHead;
    while(NULL != pHead)
    {
        temp = pHead;
        pHead = pHead->pNext;
        free(temp);
    }
    
    return pHead;
}

//遍历输出链表
void showList(perInfo *pHead)
{
    if(NULL == pHead || NULL == pHead->pNext)
    {
        printf("%s: the list is empty!\n", __func__);
        return;
    }
    perInfo *p = pHead->pNext;

    while(NULL != p)
    {
        printf("%s--%d--%s\n", p->name, p->age, p->sex);
        p = p->pNext;
    }
    return;
}

void addNodeUI(perInfo *pHead)
{
    char ch = '0';
    while(1)
    {
        system("clear");
        printf("1. 头插法\n");
        printf("2. 尾插法\n");
        printf("3. 任意位置插入\n");
        printf("0. 返回\n");
        printf("input chioce: ");
        scanf("%c", &ch);
        getchar();
        switch(ch)
        {
            case HEAD_INSERT:
            {
                headInsertNode(pHead);
                break;
            }
            case TAIL_INSERT:
            {
                tailInsertNode(pHead);
                break;
            }
            case RAND_INSERT:
            {
                int index = 0;
                printf("input position: ");
                scanf("%d", &index);
                getchar();
                randInsert(pHead,index);
                break;
            }
            case EXIT_ADD:
            {
                return;
            }
            default:
            {
                printf("input error,once again!\n");
                break;
            }
        }
    }
    return;
}

//头删法
perInfo *headDeleteNode(perInfo *pHead)
{
    if(NULL == pHead || NULL == pHead->pNext)
    {
        printf("%s:the list is empty!\n", __func__);
        return pHead;
    }

    perInfo *temp = pHead->pNext;
    //保证链的完整性
    pHead->pNext = temp->pNext;
    free(temp);
    temp = NULL;

    return pHead;
}

//尾删法
perInfo *tailDeleteNode(perInfo *pHead)
{
    if(NULL == pHead || NULL == pHead->pNext)
    {
        printf("%s: the list is empty!\n", __func__);
        return pHead;
    }

    perInfo *p = pHead;
    perInfo *temp = pHead->pNext;
#if 0
    //方法一
    for(; NULL!=temp->pNext ;p=p->pNext,temp=temp->pNext)
    {}
    
    //将倒数第二个节点的指针域置空
    p->pNext = NULL;
    //删除最后一个节点
    free(temp);
    temp = NULL;
#else
    //方法二---一个指针的形式
    while(NULL != p->pNext->pNext)
        p = p->pNext;

    //释放最后一个结点
    free(p->pNext);
    //将倒数第二个节点的指针域置空
    p->pNext = NULL;
#endif
    return pHead;
}

//任意位置删除
perInfo *randDeleteNode(perInfo *pHead,int index)
{
    if(NULL == pHead || NULL == pHead->pNext)
    {
        printf("%s:the list is empty!\n", __func__);
        return pHead;
    }
    //获得链表长度
    int iLen = getLength(pHead);
    //判断输入位置的有效性
    if(index > iLen || index < 1)
    {
        printf("index error\n");
        return pHead;
    }

    //双指针同步后移,后指针指向删除的节点
    perInfo *p = pHead;
    perInfo *temp = p->pNext;
    int i = 0;  //用于确定节点的位置

    while(temp != NULL)
    {
        //找到要删除位置的前一个位置
        if(i == index-1)
        {
            p->pNext = temp->pNext;
            free(temp);
            temp = NULL;
            return pHead;
        }
        i++;
        temp = temp->pNext;
        p = p->pNext;
    }

    return pHead;
}

//删除节点
void delNodeUI(perInfo *pHead)
{
    int ch = 0;
    while(1)
    {
        system("clear");
        printf("1. 头删法\n");
        printf("2. 尾删法\n");
        printf("3. 任意位置删除\n");
        printf("0. 返回\n");
        printf("input choice: ");
        scanf("%d", &ch);
        getchar();
        switch(ch)
        {
            case 1:
            {
                headDeleteNode(pHead);
                printf("delete successful...\n");
                sleep(2);
                break;
            }
            case 2:
            {
                tailDeleteNode(pHead);
                printf("delete successful...\n");
                sleep(2);
                break;
            }
            case 3:
            {
                int index = 0;
                printf("input index: ");
                scanf("%d", &index);
                getchar();
                randDeleteNode(pHead, index);
                printf("delete successful...\n");
                break;
            }
            case 0:
            {
                return;
            }
            default:
            {
                printf("input error!\n");
                break;
            }
        }
    }
    return;
}

//修改节点信息
int modifyNode(perInfo *pHead, char *name)
{
    if(NULL == pHead || NULL == pHead)
    {
        printf("%s:the list is empty!\n", __func__);
        return -1;
    }

    perInfo *temp = pHead->pNext;
    while(NULL != temp)
    {
        if(strcmp(temp->name,name) == 0)
        {
            printf("input age: ");
            scanf("%d", &temp->age);
            getchar();
            printf("input name: ");
            mygets(temp->name, sizeof(temp->name));
            return 1;
        }
        temp = temp->pNext;
    }

    return 0;
}

//查找节点---按姓名查找
perInfo *lookupNode(perInfo *pHead, char *name)
{
    if(NULL == pHead || NULL == pHead)
    {
        printf("%s:the list is empty!\n", __func__);
        return NULL;
    }

    perInfo *temp = pHead->pNext;
    while(NULL != temp)
    {
        if(0 == strcmp(temp->name, name))
            return temp;

        temp = temp->pNext;
    }
    return NULL;
}

int function(perInfo *pHead)
{
    char ch = '0';
    scanf("%c", &ch);
    getchar();
    switch(ch)
    {
        case ADD_NODE:
        {
            addNodeUI(pHead);
            break;
        }
        case DEL_NODE:
        {
            delNodeUI(pHead);
            break;
        }
        case MODIFY_NODE:
        {
            char name[32] = "";
            printf("input name: ");
            mygets(name, sizeof(name));
            if(modifyNode(pHead, name))
                printf("modify successful...\n");
            else
                printf("modify failed...\n");
            sleep(1);
            break;
        }
        case LOOKUP_NODE:
        {
            char name[32] = "";
            printf("input name: ");
            mygets(name, sizeof(name));
            perInfo *info = lookupNode(pHead,name);
            if(NULL != info)
                printf("%s--%d--%s\n", info->name, info->age, info->sex);
            else
                printf("the name isn't exist!\n");
            sleep(2);
            break;
        }
        case SHOW_LIST:
        {
            showList(pHead);
            sleep(2);
            break;
        }
        case EXIT:
        {
            printf("\n即将退出...\n");
            sleep(2);
            return 1;
        }
        default:
        {
            printf("input error,once again...\n");
            break;
        }
    }

    return 0;
}

void menu(perInfo *pHead)
{
    while(1)
    {
        system("clear");
        printf("1. 添加节点\n");
        printf("2. 删除节点\n");
        printf("3. 修改节点\n");
        printf("4. 查找节点\n");
        printf("5. 遍历链表\n");
        printf("0. 退出\n");
        printf("input choice: ");
        //当函数返回值为 1 时,结束循环
        if(function(pHead))     
            break;
    }
    return;
}

int main(void)
{
    //创建头节点,并初始化指针域
    perInfo *pHead = (perInfo*)malloc(SIZE);
    pHead->pNext = NULL;

    menu(pHead);
    //退出前释放所有 malloc 得到的空间
    //也即销毁链表
    destroyList(pHead);
    return 0;
}

