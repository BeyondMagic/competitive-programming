#include <stdio.h>
#include <limits.h>

int main(void)
{
  /* input */
  int n;
  scanf("%d", &n);

  /* output */
  int value, m[3];
  scanf("%d", &m[0]);
  --n;

  m[2] = m[1] = m[0];

  while (n--)
  {
    scanf("%d", &value);
    if (value <= m[0])
    {
      m[2] = m[1];
      m[1] = m[0];
      m[0] = value;
    }
    else if (value <= m[1])
    {
      m[2] = m[1];
      m[1] = value;
    } else if (value <= m[2])
      m[2] = value;
  }

  printf("%d\n%d\n", m[1], m[2]);
}
