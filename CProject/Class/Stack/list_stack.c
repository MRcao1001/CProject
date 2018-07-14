#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define STACK_SIZE 8
typedef struct Node{
    int data;
    struct Node *pNext;
}Node;
typedef struct Stack{
    Node *top;
    int ilen;
}Stack;

//产生节点
Node *makeNode(){
    Node *node = (Node *)malloc(sizeof(Node));
    if(NULL == node){
        printf("error");
        exit(EXIT_FAILURE);
    }
    memset(node, 0, sizeof(Node));
    return node;
}

//生成栈
Stack *makeStack(){
    Stack *stack = (Stack *)malloc(sizeof(stack));
    if(NULL == stack){
        printf("error");
        exit(EXIT_FAILURE);

    }
    memset(stack, 0, sizeof(stack));
    return stack;
}

//判断栈满
int isFull(const Stack *stack){
    int ret = -1;
    if(NULL != stack){
        if(STACK_SIZE == stack->ilen){
            ret = 1;
        }
        else{
            ret = 0;
        }
    }
    return ret;
}

//判断栈空
int isEmpty(const Stack *stack){
    int ret = -1;
    if(NULL != stack){
        if(0 == stack->ilen){
            ret = 1;
        }
        else{
            ret = 0;
        }
    }
    return ret;
}

//入栈判满
void push (int data, Stack *stack){
    if(NULL != stack){
        if(!isFull(stack)){
            //产生节点
            Node *node = makeNode();
            node->data = data;
            //头插法向链表添加数据
            node->pNext = stack->top;
            stack->top = node;
            stack->ilen++;
            printf("入栈时%d\n",node->data);
        }
        else{
            printf("full\n");
        }
        
    }
}

//出栈判空
Node *pop (Stack *stack){
    Node *node = NULL;
    if(NULL != stack){
        if(!isEmpty(stack)){
            node = stack->top;
            stack->top = stack->top->pNext;
            stack->ilen--;
            printf("出栈时%d\n",node->data);
        }
        else{
            printf("empty\n");
        }
    }
    else{
        printf("error\n");
    }
    return node;
}

int main(int argc, char const *argv[])
{
    /* code */
    Stack *stack = makeStack();
    push(1,stack);
    push(2,stack);
    push(3,stack);
    push(4,stack);

    Node *node = pop(stack);
    if(NULL != node){
        printf("结果%d\n",node->data);
    }
    return 0;
}
