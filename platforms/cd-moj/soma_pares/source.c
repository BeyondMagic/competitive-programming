#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
int solve (void)
{
  int soma = 0;
  int n;
  do {
    scanf("%d", &n);
    if (!(n % 2))
      soma += n;
  } while (n);
  return soma;
}

int main(void)
{
  /* output */
  printf("%d\n", solve());
}
