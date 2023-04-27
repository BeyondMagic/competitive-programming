#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool is_prime (int a)
{
  for (int i = 2; i <= sqrt(a); i++)
    if (!(a % i))
      return false;
  return true;
}

/* calculation */
char solve (int a)
{
  while (a)
  {
    if (a == 1 || !is_prime(a))
      return 'N';
    a /= 10;
  }
  return 'S';
}

int main(void)
{
  /* input */
  int a;
  scanf("%d", &a);

  /* output */
  while (a--)
  {
    int b;
    scanf("%d", &b);
    printf("%c\n", solve(b));
  }
}
