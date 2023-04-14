#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StackNode
{
  void *data;
  struct StackNode *next;
};

struct Stack
{
  size_t size;
  struct StackNode *head;
};

/*
 * @description Find whether the stack is empty or not.
 * @complexity O(1)
 * @parameters
 *   stack: to be perfomed on.
 * @returns
 *   true if empty;
 *   false if not empty;
 */
[[nodiscard("Retuned boolean value must be used.")]]
inline const bool stack_is_empty (const struct Stack *stack)
{
  return !stack || !stack->head;
}

/*
 * @description
 *   Find how many elements are in the stack.
 * @parameters
 *   stack: to be perfoemd on.
 * @returns
 *   size_t size of stack.
 */
[[nodiscard("Returned size must be used.")]]
inline const size_t stack_size (const struct Stack *stack)
{
  if (!stack_is_empty(stack))
    return stack->size;
  return 0;
}

/*
 * @description Initialises given stack or allocates new space for next node in stack and move into it.
 * @warning:
 *   Should not be used given the user needs to allocate and put data him/herself.
 *   Recommend the functions stack_emplace() or stack_push() be used instead.
 * @complexity O(1)
 * @parameters
 *   stack: stack to be perfomed on;
 * @returns
 *    0 if sucessfull.
 *   -2 if failed allocating memory for stack.
 *   -3 if failed allocating memory for stack node.
 */
 const short stack_initialise (struct Stack *stack)
{
  if (stack_is_empty(stack))
  {
    stack = (struct Stack*) malloc(sizeof(struct Stack));
    if (!stack)
      return -2;

    stack->head = (struct StackNode*) malloc(sizeof(struct StackNode));
    if (!stack->head)
      return -3;

    stack->head->next = NULL;
    stack->size = 0;
  }
  else
  {
    struct StackNode* temp = (struct StackNode*) malloc(sizeof(struct StackNode));
    if (!temp)
      return -3;

    temp->next = stack->head;
    stack->head = temp;
    stack->size++;
  }

  return 0;
}

/*
 * @description Inserts an element to the top of the stack.
 * @warning
 *   User needs to pass data that is not trivially freed,
 *   meaning allocated in heap and managed by him/herself.
 *   Recommended the function stack_push() be used instead.
 * @complexity O(1)
 * @parameters
 *   stack: stack to be perfomed on;
 *   data: data to be stored in next node,
 *   data_size: size of data type.
 * @returns
 *    0 if sucessfull.
 *   -1 if data is NULL.
 *   -2 if failed allocating memory for stack.
 *   -3 if failed allocating memory for stack node.
 */
const short stack_emplace (struct Stack *stack, void *data)
{
  if (!data)
    return -1;

  const short result_init = stack_initialise(stack);
  if (result_init)
    return result_init;

  stack->head->data = data;

  return 0;
}

/*
 * @description Copies and inserts given element to the top of the stack.
 * @complexity O(1)
 * @parameters
 *   stack: stack to be perfomed on;
 *   data: data to be stored in next node,
 *   data_size: size of data type.
 * @returns
 *    0 if sucessfull.
 *   -1 if data is NULL or data_size is 0.
 *   -2 if failed allocating memory for stack.
 *   -3 if failed allocating memory for stack node.
 *   -4 if failed allocating data for stack.
 */
const short stack_push (struct Stack *stack, const void *data, const size_t data_size)
{
  if (!data || !data_size)
    return -1;

  const short result_init = stack_initialise(stack);
  if (result_init)
    return result_init;

  stack->head->data = malloc(data_size * sizeof(char));
  if (!stack->head->data)
    return -4;
  memcpy(stack->head->data, data, data_size * sizeof(char));

  return 0;
}

/*
 * @description Removes the element from the top of the stack.
 * @complexity O(1)
 * @parameters
 *   stack: stack to be perfomed.
 * @returns
 *   true if sucessfull;
 *   false if failed.
 */
const bool stack_pop (struct Stack *stack)
{
  if (stack_is_empty(stack))
    return false;

  struct StackNode *temp = stack->head;
  stack->head = stack->head->next;
  free(temp->data);
  free(temp);
  stack->size--;

  return true;
}

/*
 * @description Returns the element from the top of the stack.
 * @complexity O(1)
 * @parameters
 *  stack: stack to be perfomed.
 * @returns
 *   NULL if failed;
 *   void pointer to stored data.
 */
[[nodiscard("Data value of top item in stack should be stored.")]]
void *stack_peek (const struct Stack *stack)
{
  if (stack_is_empty(stack))
    return NULL;

  return stack->head->data;
}

/*
 * @description: Swap the contents of one stack with another stack of same type but the size may vary
 * @complexity O(?)
 * @parameters
 *  stack_one: first stack,
 *  stack_two: second stack.
 * @returns
 *  true if successful,
 *  false if failed.
 */
const bool stack_swap (struct Stack *stack_one, struct Stack *stack_two)
{
  return true;
}
