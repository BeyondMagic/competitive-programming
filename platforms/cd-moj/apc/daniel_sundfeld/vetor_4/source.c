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
void solve (int n)
{
  int a,
      pairs[n], pairs_i = 0,
      odds[n], odds_i = 0;

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a);
    if (a % 2)
      odds[odds_i++] = i;
    else
      pairs[pairs_i++] = i;
  }

  for (int i = 0; i < pairs_i; i++)
  {
    printf("%d", pairs[i]);
    if (i != pairs_i - 1)
      putchar(' ');
  }

  putchar('\n');

  for (int i = 0; i < odds_i; i++)
  {
    printf("%d", odds[i]);
    if (i != odds_i - 1)
      putchar(' ');
  }
}

int main(void)
{
  /* output rules */
  // precision: 3

  /* input */
  int a;
  scanf("%d", &a);

  /* output */
  solve(a);
}
