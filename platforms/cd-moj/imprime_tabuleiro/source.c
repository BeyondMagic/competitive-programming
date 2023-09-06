#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
void solve (int r, int c)
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
      printf("[%03d,%03d]", i, j);
    putchar('\n');
  }
}

int main(void)
{
  /* input */
  int a, b;
  scanf("%d %d", &a, &b);

  /* output */
  solve(a, b);
}
