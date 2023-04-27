#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
  /* input */
  int maior;
  scanf("%d", &maior);

  /* calculation */
  int x;
  scanf("%d", &x);
  if (x > maior)
    maior = x;

  scanf("%d", &x);
  if (x > maior)
    maior = x;

  scanf("%d", &x);
  if (x > maior)
    maior = x;

  /* output */
  printf("%d\n", x);
}
