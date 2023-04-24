#include <stdio.h>
#include "../../data-structures/stack_linked_list/implementation.h"

typedef char Item;

#define MAX 100
#define ITEM_SIZE sizeof(Item) * MAX

int main (void)
{
  struct Stack *stack = stack_initialise(ITEM_SIZE);

  Item command[MAX], data[MAX];

  while (scanf(" %s", command) != EOF)
  {
    /* Desfazer. */
    if (*command == 'd')
    {
      if (stack_is_empty(stack))
        puts("NULL");
      else {
        memcpy(data, stack_peek(stack), ITEM_SIZE);
        puts(data);
        stack_pop(stack);
      }

    /* Inserir. */
    } else if (*command == 'i') {
      scanf(" %[^\n]s", data);
      Item *node = malloc(ITEM_SIZE);
      strcpy(node, data);
      stack_push(stack, node);
    }
  }

  stack_destroy(stack);
}
