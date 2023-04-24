#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
int solve (void)
{
  int soma = 0;
  int n;
  scanf("%d", &n);
  while (n)
  {
    if (!(n % 2))
      soma += n;
    scanf("%d", &n);
  }
  return soma;
}

int main(void)
{
  /* output */
  printf("%d\n", solve());
}
