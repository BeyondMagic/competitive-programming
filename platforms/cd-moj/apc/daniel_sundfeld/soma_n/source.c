#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
int solve (int a)
{
  int soma = 0;
  while (a--)
  {
    int n;
    scanf("%d", &n);
    soma += n;
  }
  return soma;
}

int main(void)
{
  /* input */
  int a;
  scanf("%d", &a);

  /* output */
  printf("%d\n", solve(a));
}
