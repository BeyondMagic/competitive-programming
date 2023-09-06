#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
int solve (int a)
{
  int maior;
  scanf("%d", &maior);
  a--;

  while (a--)
  {
    int n;
    scanf("%d", &n);
    if (n > maior)
      maior = n;
  }
  return maior;
}

int main(void)
{
  /* input */
  int a;
  scanf("%d", &a);

  /* output */
  printf("%d\n", solve(a));
}
