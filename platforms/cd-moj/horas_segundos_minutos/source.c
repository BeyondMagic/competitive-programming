#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
void solve (size_t a)
{
  printf("%zu\n", a * 60);
  printf("%zu\n", a * 60 * 60);
}

int main(void)
{
  /* input */
  size_t a;
  scanf("%zu", &a);

  /* output */
  solve(a);
}
