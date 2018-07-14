#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 8

typedef struct Stack
{
	int iaData[STACK_SIZE];
	int top;
}Stack;

int isFull(const Stack *stack)
{
	int ret = -1;
	if (NULL != stack)
	{
		if (stack->top == STACK_SIZE)
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
	//if (0 == isFull(stack))
	if (!isFull(stack))
	{
		stack->iaData[stack->top] = data;
		stack->top++;
	}
	else
	{
		printf("stack error or full !\n");
	}
}

int isEmpty(const Stack *stack)
{
	int ret = -1;
	if (NULL != stack)
	{
		if (0 == stack->top)
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

void pop(Stack *stack)
{
	if (NULL != stack)
	{
		//if (0 == isEmpty(stack))
		if (!isEmpty(stack))
		{
			stack->iaData[stack->top-1] = 0;
			stack->top--;
		}
		else
		{
			printf("stack is empty\n");
		}
	}
}

int getTopData(Stack *stack)
{
	int data = 0;
	if (NULL != stack)
	{
		if (!isEmpty(stack))
		{
			data = stack->iaData[stack->top-1];
			pop(stack);
		}
		else
		{
			printf("stack error or empty !\n");
		}
	}
	return data;
}

int main(void)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	memset(stack, 0, sizeof(Stack));
	push(1, stack);
	push(2, stack);
	push(3, stack);
	push(4, stack);
	push(11, stack);
	push(22, stack);
	push(33, stack);
	push(44, stack);

	push(888, stack);

	printf("%d\n", getTopData(stack));
	pop(stack);
	pop(stack);
	printf("%d\n", getTopData(stack));
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	printf("--------------\n");
	pop(stack);
#if 0
	Stack stack;
	memset(&stack, 0, sizeof(Stack));
	push(1, &stack);
	push(2, &stack);
	push(3, &stack);
	push(4, &stack);

	printf("%d\n", getTopData(&stack));
	pop(&stack);
	pop(&stack);
	printf("%d\n", getTopData(&stack));
#endif
	return 0;
}
