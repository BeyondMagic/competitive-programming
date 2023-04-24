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
void solve (int n)
{
  while (n--)
  {
    int a;
    scanf("%d", &a);
    bool prime = true;
    while (a)
    {
      if (a == 1 || !is_prime(a))
      {
        prime = false;
        break;
      }
      a /= 10;
    }

    printf("%c\n", prime ? 'S' : 'N');
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
