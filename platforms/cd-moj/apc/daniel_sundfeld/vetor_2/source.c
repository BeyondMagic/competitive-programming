#include <stdio.h>

int main(void)
{
  /* input */
  int a;
  scanf("%d", &a);

  /* output */
  int m, mi = 0, i;
  scanf("%d", &m);
  for (i = 0; i < a; i++)
  {
    scanf("%d", &m);
    if (a < m)
    {
      m  = a;
      mi = i;
    }
  }
  printf("%d\n", mi);
}
