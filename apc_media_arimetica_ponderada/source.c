#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
double solve (double x, double x2, double p1, double p2)
{
  /* * Resolve for x1.
   * x = (x1 * p1 + x2 * p2) / (p1 + p2)
   * x * (p1 + p2) = x1 * p1 + x2 * p2
   * x * (p1 + p2) - x2 * p2 = x1 * p1 + x2 * p2 - x2 * p2
   * x * (p1 + p2) - x2 * p2 = x1 * p1
   * (x * (p1 + p2) - x2 * p2)/p1 = x1 * p1 / p1
   * (x * (p1 + p2) - x2 * p2)/p1 = x1
   */
  return (x * (p1 + p2) - x2 * p2) / p1;
}

int main(void)
{
  /* output rules */
  // precision: 6

  /* input */
  double a, b, c, d;
  scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

  /* output */
  printf("%.6lf\n", solve(a, b, c, d));
}
