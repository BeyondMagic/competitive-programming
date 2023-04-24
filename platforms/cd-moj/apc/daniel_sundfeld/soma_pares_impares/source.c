#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
void solve ()
{
  int par = 0, impar = 0;
  int a;
  scanf("%d", &a);
  while (a)
  {
    if (a % 2)
      impar += a;
    else
      par += a;
    scanf("%d", &a);
  }

  printf("%d %d\n", par, impar);
}

int main(void)
{
  /* output */
  solve();
}
