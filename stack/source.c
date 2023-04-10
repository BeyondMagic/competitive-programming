#include <stdio.h>
#include "stack.h"

#define MAX 100
#define Item char

int main (void)
{
  struct Stack *head = NULL;
  char a;
  Item data[MAX];
  while (scanf("%c%*s ", &a) != EOF)
    /* Desfazer. */
    if (a == 'd')
    {
    /* Inserir. */
    } else {
      scanf("%s ", data);
      stack_push(head, data, MAX * sizeof(Item));
    }
}
