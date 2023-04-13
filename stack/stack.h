#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack
{
  void *data;
  struct Stack *next;
};

/*
 * @description It inserts an element to the top of the stack.
 * @complexity O(1)
 * @parameters
 * @returns
 *    0 if sucessfull.
 *   -1 if failed allocating memory for first stack.
 *   -2 if failed allocating memory for next stack.
 *   -3 if failed allocating data for stack.
 **/
bool stack_push (struct Stack *head, const void *data, size_t data_size)
{
  if (!head)
  {
    head = (struct Stack*) malloc(sizeof(struct Stack));
    if (!head)
      return -1;
    head->next = NULL;
  }
  else
  {
    struct Stack* temp = (struct Stack*) malloc(sizeof(struct Stack));
    if (!temp)
      return -2;
    temp->next = head;
    head = temp;
  }

  head->data = malloc(data_size * sizeof(char));
  if (!head->data)
    return -3;

  memcpy(head->data, data, data_size * sizeof(char));
  return 0;
}

/*
 * @description It removes an element from the top of the stack.
 * @complexity O(1)
 * @parameters
 *   head: stack to be perfomed.
 * @returns
 *   true if sucessfull;
 *   false if failed.
 **/
bool stack_pop (struct Stack *head)
{
  if (!head)
    return false;

  struct Stack *temp = head;
  head = head->next;
  free(temp->data);
  free(temp);

  return true;
}

/*
 * @description It returns a boolean value indicating whether
 * @complexity O(1)
 * @parameters
 * @returns
 *   true if empty;
 *   false if not empty;
 */
[[nodiscard("A verifier's return value gives its reason.")]]
inline bool stack_is_empty (struct stack *head)
{
  return !head;
}
