#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
void solve (int t)
{
  for (int l = 1; l <= t; l++)
  {
    for (int c = 1; c <= l; c++)
    {
      printf("%02d", l);
      if (c != l)
        putchar(' ');
    }
    putchar('\n');
  }

  putchar('\n');

  for (int l = 1; l <= t; l++)
  {
    for (int c = 1; c <= l; c++)
    {
      printf("%02d", c);
      if (c != l)
        putchar(' ');
    }
    putchar('\n');
  }
}

int main(void)
{
  /* input */
  int a;
  scanf("%d", &a);

  /* output */
  solve(a);
}
