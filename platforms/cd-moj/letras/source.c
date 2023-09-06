#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char letra;
	scanf("%c\n", &letra);

	char str[1000];
	fgets(str, 1000, stdin);

	int a = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		a++;
	}

	int contador = 0;
	for (int i = 0; i < a; i++) {
		if (str[i] == letra) {
			contador++;
		}
	}

	double porcentagem = (contador * 100.0) / a;
	printf("%0.1lf\n", porcentagem);
}
