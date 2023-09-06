#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* calculation */
size_t solve (size_t a)
{
  return a * a;
}

int main(void)
{
  /* output rules */
  // precision: 3

  /* input */
  size_t a;
  scanf("%zu", &a);
  /* output */
  printf("%zu\n", solve(a));
}
