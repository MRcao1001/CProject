#include "./atm.h"

int armFunc(userNode *pHead)
{
    //实现: 取款，存款，修改密码，查询余额
    return 0;
}

int loginSuccessful(userNode *pHead)
{
    while(1)
    {
        system("clear");
        atmUI();
        if(atmFunc(pHead))
            break;
    }

    return 0;
}

int accountCheck(userNode *pHead, long cardId, long passwd)
{
    userNode *temp = pHead->pNext;
    while(NULL != temp)
    {
        if(temp->data.cartID == cardId && temp->data.passwd == passwd)
        {
            printf("\t登录成功!\n");
            loginSuccessful(pHead);
        }
        temp = temp->pNext;
    }
    if(NULL == temp)
    {
        printf("\t登录失败!\n");
        return -1;
    }
    return 0;
}

void loginUI(userNode *pHead)
{
    long cardId = 0;
    long passwd = 0;

    while(1)
    {
        system("clear");
        printf("\n\n\n\t输入卡号: ");
        cardId = myscanf();
        printf("\t输入密码: ");
        passwd = myscanf();
        //密码和帐号的匹配
    }

    return ;
}



int main(void)
{

    userNode *pHead = readFromFile();

    loginUI(pHead);
    
    return 0;
}


