#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* */
#define CLOSE_EQUAL_DECIMAL(a, b, epsilon) (fabs((a) - (b)) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * (epsilon)))
#define ESSENTIALLY_EQUAL_DECIMAL(a, b, epsilon) (fabs((a) - (b)) <= ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * (epsilon)))

/* */
#define GREATER_DECIMAL(a, b, epsilon) ((a) - (b)) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * (epsilon))
#define LESS_DECIMAL(a, b, epsilon) (((b) - (a)) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * (epsilon)))

/* Maximum number from two integers. */
#define MAX_INT(a, b) (((a) > (b)) ? (a) : (b))
#define MIN_INT(a, b) (((a) < (b)) ? (a) : (b))

/* Maximum number from two doubles. */
#define MAX_DECIMAL(a, b, epsilon) (GREATER_DECIMAL(a, b, epsilon) ? (a) : (b)))
#define MIN_DECIMAL(a, b, epsilon) (LESS_DECIMAL(a, b, epsilon) ? (a) : (b)))

/* Basic mathematical logics. */
#define IS_EVEN(integer) ((long long) (integer) % 2)
#define IS_ODD(integer) (!(IS_EVEN(integer)))

/* calculation */
int solve (int a)
{
  return a * 2;
}

int main(void)
{
  /* input */
  int array[5];
  for (int i = 0; i < 5; ++i)
    scanf("%d", &array[i]);

  bool a = true, d = true;
  for (int i = 0; (a || d) && i < 5 - 1; i++)
  {
    int b;
    scanf("%d", &b);
    if (array[i] < array[i+1])
      d = false;
    else if (array[i] > array[i+1])
      a = false;
  }

  /* output */
  if (a)
    puts("C");
  else if (d)
    puts("D");
  else
    puts("N");
}
