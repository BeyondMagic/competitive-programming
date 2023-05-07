#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* Comparing operations to be used only with real numbers. */
#define EQUAL_DECIMAL(a, b, epsilon)   (fabs((a) - (b)) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * (epsilon)))
#define GREATER_DECIMAL(a, b, epsilon) (((a) - (b)) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * (epsilon)))
#define LESS_DECIMAL(a, b, epsilon)    (((b) - (a)) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * (epsilon)))

/* Maximum number from two doubles. */
#define MAX_DECIMAL(a, b, epsilon) (GREATER_DECIMAL(a, b, epsilon) ? (a) : (b)))
#define MIN_DECIMAL(a, b, epsilon) (LESS_DECIMAL(a, b, epsilon) ? (a) : (b)))

/* Maximum number from two integers. */
#define MAX_INT(a, b) (((a) > (b)) ? (a) : (b))
#define MIN_INT(a, b) (((a) < (b)) ? (a) : (b))

/* Basic mathematical logics. */
#define IS_EVEN(integer) ((long long) (integer) % 2)
#define IS_ODD(integer) (!(IS_EVEN(integer)))

/* calculation */
void solve (int n, int array[])
{
  int average = 0;
  for (int i = 0; i < n; i++)
    average += array[i];
  average /= n;
  
  int elements = 0;
  for (int i = 0; i < n; i++)
    if (array[i] > average)
    {
      printf("%d", array[i]);
      if (i != n - 1)
        putchar(' ');
      elements++;
    }

  if (!elements)
    puts("0");
}

int main(void)
{
  /* input */
  int a;
  scanf("%d", &a);

  int b[a];
  for (int i = 0; i < a; i++)
    scanf("%d", &b[i]);

  /* output */
  solve(a, b);
}
