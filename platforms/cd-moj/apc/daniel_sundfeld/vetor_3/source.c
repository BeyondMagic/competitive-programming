#include <stdio.h>

int main(void)
{
  /* output rules */
  // precision: 3

  /* input */
  int n;
  scanf("%d", &n);

  /* output */
  int a,
      pairs[n], pairs_i = 0,
      odds[n], odds_i = 0;
  while (n--)
  {
    scanf("%d", &a);
    if (a % 2)
      pairs[pairs_i++] = a;
    else
      odds[odds_i++] = a;
  }

  for (int i = 0; i < odds_i; i++)
  {
    printf("%d", odds[i]);
    if (i != odds_i - 1)
      putchar(' ');
  }

  putchar('\n');

  for (int i = 0; i < pairs_i; i++)
  {
    printf("%d", pairs[i]);
    if (i != pairs_i - 1)
      putchar(' ');
  }
}
