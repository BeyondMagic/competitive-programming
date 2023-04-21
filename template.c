#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* calculation */
int solve (int a)
{
  return a * 2;
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
