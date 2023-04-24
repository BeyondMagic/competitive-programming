#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* calculation
 * pedagios = distancia / distancia_per_pedagio
 * */
int solve (int l, int d, int k, int p)
{
  const int pedagios = l / d;
  const int custos_pedagios = pedagios * p;
  const int custos_gasolina = l * k;
  return custos_pedagios + custos_gasolina;
}

int main(void)
{
  /* output rules */
  // precision: 3

  /* input */
  int a, b, c, d;
  scanf("%d %d\n%d %d", &a, &b, &c, &d);

  /* output */
  printf("%d\n", solve(a, b, c, d));
}
