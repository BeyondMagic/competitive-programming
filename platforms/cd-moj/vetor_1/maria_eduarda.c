#include <stdio.h>

int main()
{
	int n;
	int segundomenor;
	int terceiromenor;
	int menor;

	scanf("%d", &n);

	int vet[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &vet[i]);
	}

	for (int i = 0; i < n; i++) {
		if (vet[i] < menor) {
			terceiromenor = segundomenor;
			segundomenor = menor;
			menor = vet[i];
		}

		else if (vet[i] < segundomenor && vet[i] != menor) {
			terceiromenor = segundomenor;
			segundomenor = vet[i];
		}

		else if (vet[i] < terceiromenor && vet[i] != segundomenor) {
			terceiromenor = vet[i];
		}
	}

	printf("%d\n", segundomenor);
	printf("%d\n", terceiromenor);

	return 0;
}
