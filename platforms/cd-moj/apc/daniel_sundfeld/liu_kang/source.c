#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* calculation */
void solve (size_t t, size_t g)
{
  for (size_t i = 1; i <= g; i++) {
    size_t n = (size_t) sqrt( (double) t);

    // Se o tempo atual e par.
    if (!(t % 2)) {
        t = ( n - 1 ) * ( n - 1 );
    }

    // Caso contrario, o tempo atual e impar.
    else {
      t = ( 2 * n - 1 ) * ( 2 * n - 1 );
    }

    printf("%zu\n", t);
  }
}

int main(void)
{
  /* input */
  size_t a, b;
  scanf("%zu %zu", &a, &b);

  /* output */
  solve(a, b);
}
