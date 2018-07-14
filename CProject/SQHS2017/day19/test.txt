#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>

typedef struct stack
{
    int c;
    struct stack *pNext;
}Stack;

#define LEN sizeof(struct stack)

Stack *pHead = NULL;
Stack *top = NULL;  //栈顶指针

//入栈操作
void mypush(int c)
{
    Stack *temp = (Stack*)malloc(LEN);
    temp->c = c;
    temp->pNext = NULL;
    
    temp->pNext = pHead->pNext;
    pHead->pNext = temp;

    top = temp;     //保证 top 始终指向栈顶
    temp = NULL;
    return;
}

//判断是否是空栈
bool isEmpty()
{
    if(NULL == top)
        return true;
    else
        return false;
}

//错误处理
int handleError(const char *message)
{
    printf("%s\n", message);
    exit(1);    //结束程序
}

//出栈操作
int mypop()
{
    //判断是否空栈，若空栈则直接退出
    if(isEmpty())
        handleError("the stack is empty!\n");
    
    int value = 0;  //返回栈顶元素
    value = top->c;

    pHead->pNext = top->pNext;
    free(top);              //释放当前出栈元素
    top = pHead->pNext;     //top 指向栈顶元素
    return value;
}

int main(void)
{
    pHead = (Stack*)malloc(LEN);
    pHead->pNext = NULL;
    int c = 0;
    //将 1,2,3,4 循环入栈
    for(c=1; c<5; c++)
        mypush(c);
    //循环出栈:将栈里元素逐个拿出
    for(c=1; c<5; c++)
        printf("%d\n", mypop());
    return 0;
}


