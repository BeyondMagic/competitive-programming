#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

int main()
{
  int linhas, max_anterior = -1;

  int pos[2];

  scanf("%d\n", &linhas);
  char strings[linhas][MAX];

  for (int i = 0; i < linhas; i++)
    fgets(strings[i], MAX, stdin);
  scanf("%d %d\n", &pos[0], &pos[1]);

  --pos[0];
  --pos[1];

  char next_pos;

  while (scanf("%c\n", &next_pos) != EOF) {

    if (next_pos == 'j' && pos[0] + 1 < linhas)
      pos[0]++;
    else if (next_pos == 'k' && pos[0] - 1 >= 0)
      pos[0]--;

    int tamanho = 0;
    for (; strings[pos[0]][tamanho] != '\n'; tamanho++)
      ;

    if (pos[1] < max_anterior) {
      pos[1] = max_anterior;
      max_anterior = -1;
    }

    // printf("%d %d\n", pos[1], tamanho);

    if (pos[1] >= tamanho) {
      max_anterior = pos[1];
      pos[1] = tamanho - 1;
    }

    printf("%d %d %c\n", pos[0] + 1, pos[1] + 1, strings[pos[0]][pos[1]]);
  }

  return EXIT_SUCCESS;
}
