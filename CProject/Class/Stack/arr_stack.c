#include <stdio.h>
#include <string.h>
#define STACK_SIZE 8

//创建栈的数据类型
typedef struct Stack{
    int iaData[STACK_SIZE];
    int top;
}Stack;

//判断栈满
int isFull(const Stack *stack){
    int ret = -1;
    if(NULL != stack){
        if(stack->top == STACK_SIZE){
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
        if(0 == stack->top){
            ret = 1;
        }
        else{
            ret = 0;
        }
    }
    return ret;
}

//弹出数据
void pop(Stack *stack){
    if(NULL != stack){
        if(!isEmpty(stack)){
            stack ->iaData[stack->top-1]=0;
            stack->top--;
        }
    }
}

//获取栈顶数据
int getTopData(Stack *stack){
    int data = 0;
    if(NULL != stack){
        if(!isEmpty(stack)){
            data = stack->iaData[stack->top -1];
            pop(stack);
        }
        else{
            printf("is empty");
        }
    }
    return data;
}
//创建栈
void push(int data, Stack *stack){
    if(!isFull(stack)){
        stack->iaData[stack->top] = data;
        stack->top++;
    }   
    else{
        printf("Stack over flow");
    } 
}

int main(int argc, char const *argv[])
{
    /* code */
    Stack stack;
    memset(&stack,0,sizeof(Stack));
    push(1,&stack);
    push(2,&stack);
    push(3,&stack);
    push(4,&stack);

    printf("%d",getTopData(&stack));
    pop(&stack);
    pop(&stack);
    printf("%d\n",getTopData(&stack));
    return 0;
}
