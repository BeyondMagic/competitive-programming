#include <stdio.h>
#include <limits.h> // INT_MAX

/* calculation */
void solve (int n)
{
  int a, m[3] = { INT_MAX, INT_MAX, INT_MAX };

  while (n--)
  {
    scanf("%d", &a);
    if (a < m[0])
    {
      m[2] = m[1];
      m[1] = m[0];
      m[0] = a;
    }
    else if (a < m[1])
    {
      m[2] = m[1];
      m[1] = a;
    } else if (a < m[2])
      m[2] = a;
  }

  printf("%d\n%d\n", m[1], m[2]);
}

int main(void)
{
  /* input */
  int a;
  scanf("%d", &a);

  /* output */
  solve(a);
}
