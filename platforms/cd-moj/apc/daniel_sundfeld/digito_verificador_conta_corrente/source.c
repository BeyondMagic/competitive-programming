#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
int solve (int a)
{
  int d1 = a % 10;
  a /= 10;

  int d2 = a % 10;
  a /= 10;

  int d3 = a % 10;
  a /= 10;

  int d4 = a % 10;
  a /= 10;

  int d5 = a % 10;
  a /= 10;

  int d6 = a % 10;
  a /= 10;

  int res = d1 * 2 + d2 * 3 + d3 * 4 + d4 * 5 + d5 * 6 + d6 * 7;

  res %= 11;
  res = 11 - res;

  return res;
}

int main(void)
{
  /* input */
  int a;
  scanf("%d", &a);

  /* output */
  printf("%d\n", solve(a));
}
