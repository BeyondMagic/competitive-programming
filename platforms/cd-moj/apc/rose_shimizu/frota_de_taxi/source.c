#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* */
#define CLOSE_EQUAL_DECIMAL(a, b, epsilon)       (fabs((a) - (b)) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * (epsilon)))
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
char solve (float a, float g, float ra, float rg)
{
  float pa = a / ra;
  float pg = g / rg;
  return pa < pg ? 'A' : 'G';
}

int main(void)
{
  /* output rules */
  // precision: 3

  /* input */
  float a, b, c, d;
  scanf("%f %f %f %f", &a, &b, &c, &d);

  /* output */
  printf("%c\n", solve(a, b, c, d));
}
