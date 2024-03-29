#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MIN 10000
#define MAX 100 + MIN
#define DATA_TYPE char *

struct Node
{
	DATA_TYPE data;
	struct Node *link;
};

struct Stack
{
	struct Node *top;
};

struct Stack *stack_initialise()
{
	struct Stack *stack = malloc(sizeof(struct Stack));
	stack->top = NULL;
	return stack;
}

bool stack_is_empty(struct Stack *stack)
{
	return stack->top == NULL;
}

DATA_TYPE stack_peek(struct Stack *stack)
{
	if (!stack->top)
		return NULL;
	return stack->top->data;
}

bool stack_push(struct Stack *stack, const DATA_TYPE data)
{
	struct Node *temp = malloc(sizeof(struct Node));

	if (!temp)
		return false;

	temp->data = strndup(data, MAX);

	temp->link = stack->top;

	stack->top = temp;

	return true;
}

bool stack_pop(struct Stack *stack)
{
	if (!stack->top)
		return false;

	struct Node *temp = stack->top;

	stack->top = stack->top->link;

	free(temp);
	
	return true;
}

void stack_destroy(struct Stack *stack)
{
	while (stack_is_empty(stack))
		stack_pop(stack);

	free(stack);
}

int main(void)
{
	char str[MAX]; // frase

	struct Stack *stack = stack_initialise();

	while (scanf("%s", str) != EOF)
	{
		// desfazer
		if (str[0] == 'd')
		{
			if (stack_is_empty(stack))
			{
				puts("NULL");
				continue;
			}

			DATA_TYPE str = stack_peek(stack);
			if (str)
				puts(str);
			stack_pop(stack);

			continue;
		} else {
			// inserir
			// read rest of line
			scanf(" %[^\n]s", str);
			stack_push(stack, str);
		}
	}

	// stack_destroy(stack);
}
