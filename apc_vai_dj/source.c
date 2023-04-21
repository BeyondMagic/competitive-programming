#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* calculation */
void solve (int a)
{
  for (int i = 1; i <= a; i++)
    if (i % 2)
      puts("THUMS THUMS THUMS");
    else
      puts("THUMS THUMS THUMS THUMS THUMS THUMS");
}

int main(void)
{
  /* input */
  int a;
  scanf("%d", &a);

  /* output */
  solve(a);
}
