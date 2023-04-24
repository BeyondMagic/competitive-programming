#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

/* calculation */
int solve (int xm, int ym, int xr, int yr)
{
  return MAX(xm, xr) - MIN(xm, xr) + MAX(ym, yr) - MIN(ym, yr);
}

int main(void)
{
  /* input */
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);

  /* output */
  printf("%d\n", solve(a, b, c, d));
}
