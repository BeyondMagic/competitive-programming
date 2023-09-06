#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* */
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
int solve (int m)
{
  int preco = 0;

  #define REMOVE_PRICE(v, t)    \
    if (m > v)                  \
    {                           \
      preco += t * (m - v);     \
      m -= m - v;               \
    }

  REMOVE_PRICE(100, 5);
  REMOVE_PRICE(30, 2);
  REMOVE_PRICE(10, 1);

  return preco + 7;
}

int main(void)
{
  /* output rules */
  // precision: 3

  /* input */
  int a;
  scanf("%d", &a);

  /* output */
  printf("%d\n", solve(a));
}
