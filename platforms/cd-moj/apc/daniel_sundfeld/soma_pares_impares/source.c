#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
void solve ()
{
  int par = 0, impar = 0;
  int a;
  do {
    scanf("%d", &a);

    if (a % 2)
      impar += a;
    else
      par += a;

  } while (a);

  printf("%d %d\n", par, impar);
}

int main(void)
{
  /* output */
  solve();
}
