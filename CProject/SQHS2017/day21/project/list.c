#include "./list.h"
#include "./public.h"

/***********************************
*函 数 名：
*功能实现：
*输入参数：
*返 回 值：
************************************/
userNode *makeNode()
{
    userNode *newNode = (userNode*)malloc(NODE_LEN);
    if(NULL == newNode)
        newNode = (userNode*)malloc(NODE_LEN);
    newNode->pNext = NULL;
    return newNode;
}

//获得数据域的基本信息
int getData(perInfo *temp)
{
    system("clear");
    printf("\n\n\t\t       信息录入\n");
    printf("\t=========================================\n");
    printf("\t\t姓名: ");
    mygets(temp->name, sizeof(temp->name));

    printf("\t\t卡号: ");
    temp->cardID = myscanf();

    printf("\t\t身份证号: ");
    temp->ID = myscanf();

    //密码初始化为: 111111
    temp->passwd = 111111;

    printf("\t\t电话: ");
    temp->phoneNum = myscanf();

    printf("\t\t金额: ");
    temp->balance = myscanf();

    return 0;
}

//添加用户---头插法
int addUser(userNode *pHead)
{
    return 0;
}

//销毁用户 --- 按 cardID
int deleteUser(userNode *pHead, long cardID)
{
    return 1;
}

//修改用户信息 --- 按 cardID,返回用户信息节点
int updateUser(userNode *pHead, long cardID)
{
    return 0;
}

//查找用户信息 --- 按 cardID,返回用户信息节点
userNode *lookupUser(userNode *pHead, long cardID)
{
    return NULL;
}

//显示所有用户
void showAllUser(userNode *pHead)
{
    return;
}

//保存数据---写文件
void writeToFile(userNode *pHead)
{
    return;
}

//加载数据---读文件
userNode *readFromFile()
{
    userNode *pHead = makeNode();
    return pHead;
}

//销毁用户数据链表
void destroyList(userNode *pHead)
{
    return;
}

