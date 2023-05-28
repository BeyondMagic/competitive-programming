#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 101

int main(void)
{
  /* input */
  size_t n_a, n_b;
  scanf("%zu %zu", &n_a, &n_b);
  char a[n_a][MAX], b[n_b][MAX];

  for (size_t i = 0; i < n_a; i++)
    scanf("%s", a[i]);

  for (size_t i = 0; i < n_b; i++)
    scanf("%s", b[i]);

  int has = 0;
  for (size_t i = 0; i < n_a && !has; i++)
  {
    for (size_t j = 0; j < n_b && !has; j++)
    {
      bool equal = true;
      for (size_t m = 0; equal && (a[i][m] || b[j][m]); m++)
        if (a[i][m] != b[j][m])
          equal = false;
      if (equal)
        has = 1;
    }
  }

  /* output */
  printf("%d\n", has);
}
