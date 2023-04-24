#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* calculation */
int solve (int a, int b)
{
  return a - b;
}

int main(void)
{
  /* output rules */
  // precision: 3

  /* input */
  int a, b;
  scanf("%d %d", &a, &b);

  /* output */
  printf("%d\n", solve(a, b));
}
