#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
int solve (int a, int b, int c, int d)
{
  if (a >= b && a >= c && a >= d)
    return a;
  else if (b >= a && b >= c && b >= d)
    return b;
  else if (c >= a && c >= b && c >= d)
    return c;
  else
    return d;
}

int main(void)
{
  /* input */
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);

  /* output */
  printf("%d\n", solve(a, b, c, d));
}
