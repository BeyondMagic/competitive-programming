#include <stdio.h>
#include <ctype.h>

#define MIN 1
#define MAX 100 + MIN

void string_lower (char string[])
{
  for (size_t i = 0; string[i]; i++)
    string[i] = (char) tolower(string[i]);
}

int main(void)
{
  /* input */
  char word[MAX];
  scanf("%s", word);
  string_lower(word);
  printf("%s.", word);
  while (scanf("%s", word) != EOF);
  string_lower(word);
  printf("%s@unb.br\n", word);
}
