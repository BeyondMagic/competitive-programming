#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define IS_EVEN(integer) ((long long) (integer) % 2)
#define IS_ODD(integer) (!(IS_EVEN(integer)))

/* calculation */
void solve (double t, size_t g)
{
  while (g--)
  {
    double n = sqrt(t);

    // Se o tempo atual e par.
    if (IS_ODD(t))
        t = pow(n - 1, 2);

    // Caso contrario, o tempo atual e impar.
    else
      t = pow(2 * n - 1, 2);

    printf("%.0lf\n", t);
  }
}

int main(void)
{
  /* input */
  double a;
  size_t b;
  scanf("%lf %zu", &a, &b);

  /* output */
  solve(a, b);
}
