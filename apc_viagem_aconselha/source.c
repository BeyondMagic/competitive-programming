#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* calculation */
size_t solve (size_t m)
{
  size_t n = 0, cod = 0;
  while (m--)
  {
    size_t a, b;
    scanf("%zu %zu", &b, &a);
    if ( (a > n) || (a == n && b < cod) )
    {
      n = a;
      cod = b;
    }
  }
  return cod;
}

int main(void)
{
  /* input */
  size_t n, day = 1;
  while (scanf("%zu", &n) != EOF)
    /* output */
    printf("Dia %zu\n%zu\n", day++, solve(n));
}
