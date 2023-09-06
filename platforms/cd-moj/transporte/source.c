#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* calculation */
int solve (int a, int b, int c, int x, int y, int z)
{
  return (x / a) * (y / b) * (z / c);
}

int main(void)
{
  /* input */
  int a, b, c, d, e, f;
  scanf("%d %d %d\n%d %d %d", &a, &b, &c, &d, &e, &f);

  /* output */
  printf("%d\n", solve(a, b, c, d, e, f));
}
