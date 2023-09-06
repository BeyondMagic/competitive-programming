#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* calculation */
int solve (int m)
{
  int n = -1, cod = -1;
  while (m--)
  {
    int a, b;
    scanf("%d %d", &b, &a);
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
  int n, day = 1;
  while (scanf("%d", &n) != EOF)
    /* output */
    printf("Dia %d\n%d\n\n", day++, solve(n));
}
