#include <stdio.h>

#define MIN 1
#define MAX 1000 + MIN

int main (void)
{
  /* input */
  size_t n;
  scanf("%zu", &n);

  size_t biggest = 0;
  while (n--)
  {
    char word[MAX];
    scanf("%s", word);
    size_t i;
    for (i = 0; word[i]; ++i);
    if (i > biggest)
      biggest = i;
  }

  /* output */
  printf("%zu\n", biggest);
}
