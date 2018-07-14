#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 8

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

typedef struct Stack
{
	Node *top;
	int iLen;
}Stack;

Node *mkNode()
{
	Node *node = (Node *)malloc(sizeof(Node));
	if (NULL == node)
	{
		printf("malloc faield\n");
		exit(EXIT_FAILURE);
	}
	memset(node, 0, sizeof(Node));
	return node;
}

Stack *mkStack()
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	if (NULL == stack)
	{
		printf("malloc faield\n");
		exit(EXIT_FAILURE);
	}
	memset(stack, 0, sizeof(Stack));
	return stack;

}

int isFull(const Stack *stack)
{
	int ret = -1;
	if (NULL != stack)
	{
		if (STACK_SIZE == stack->iLen)
		{
			ret = 1;
		}
		else
		{
			ret = 0;
		}
	}
	return ret;
}

void push(int data, Stack *stack)
{
	if (NULL != stack)
	{
		if (!isFull(stack))
		{
			Node *node = mkNode();
			node->data = data;
			//头插法
			//原来的第一个作为新节点的下一个
			node->next = stack->top;
			//新节点作为第一个节点
			stack->top = node;
			stack->iLen++;
		}
		else
		{
			printf("stack full !\n");
		}
	}
}

int isEmpty(const Stack *stack)
{
	int ret = -1;
	if (NULL != stack)
	{
		if (0 == stack->iLen)
		{
			ret = 1;
		}
		else
		{
			ret = 0;
		}
	}
	return ret;
}

Node *pop(Stack *stack)
{
	Node *node = NULL;
	if (NULL != stack)
	{
		if (!isEmpty(stack))
		{
			//获得第一个节点
			node = stack->top;
			//将第二个节点作为第一个节点
			stack->top = stack->top->next;
			stack->iLen--;
		}
	}
	return node;
}

int main(void)
{
	Stack *stack = mkStack();
	push(1, stack);
	push(2, stack);
	push(3, stack);
	push(4, stack);

	Node *node = pop(stack);
	if (NULL != node)
	{
		printf("data = %d\n", node->data);
	}
	else
	{
		printf("stack error or empty !\n");
	}
	pop(stack);
	pop(stack);
	node = pop(stack);
	if (NULL != node)
	{
		printf("data = %d\n", node->data);
	}
	else
	{
		printf("stack error or empty !\n");
	}

	return 0;
}







