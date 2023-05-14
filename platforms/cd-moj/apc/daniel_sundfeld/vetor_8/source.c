#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* calculation */
void solve (int n, int array[])
{
  int average = 0;
  for (int i = 0; i < n; i++)
    average += array[i];
  average /= n;
  
  int elements = 0;
  for (int i = 0; i < n; i++)
    if (array[i] > average)
    {
      printf("%d", array[i]);
      if (i != n - 1)
        putchar(' ');
      elements++;
    }

  if (!elements)
    puts("0");
}

int main(void)
{
  /* input */
  int a;
  scanf("%d", &a);

  int b[a];
  for (int i = 0; i < a; i++)
    scanf("%d", &b[i]);

  /* output */
  solve(a, b);
}
