#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* calculation */
int solve (int a, int b, int c, int d)
{
  return a + b + c + d - 3;
}

int main(void)
{
  /* input */
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);

  /* output */
  printf("%d\n", solve(a, b, c, d));
}
