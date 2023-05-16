#include <stdio.h>

int main (void)
{
  size_t N;
  scanf("%zu", &N);

  size_t matriz[N][N];

  /* Ler matriz fazendo sua transposta, colunas por linhas. */
  for (size_t l = 0; l < N; l++)
    for (size_t c = 0; c < N; c++)
      scanf("%zu", &matriz[c][l]);

  size_t column = 0;
  /* Ler qual linha (originalmente coluna) é maior. */
  {
    size_t bigger = 0;
    for (size_t l = 0; l < N; l++)
    {
      size_t row = 0;

      for (size_t c = 0; c < N; c++)
        row += matriz[l][c];

      if (bigger < row)
      {
        bigger = row;
        column = l;
      }
    }
  }

  printf("%zu\n", column + 1);
}
