#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main ()
{
	int Cv, Ce, Cs, Fv, Fe, Fs;
	scanf ("%d %d %d %d %d %d", &Cv, &Ce, &Cs, &Fv, &Fe, &Fs);

	int pontosc;
	int pontosf;

	pontosc = (Cv*3) + (Ce*1);
	pontosf = (Fv*3) + (Fe*1);

	if (pontosc > pontosf) // se a pontuação de C for MAIOR que F 
	{
		printf ("C\n"); // imprima C
	}

	if (pontosf > pontosc)
	{
		printf ("F\n");
	}

	if (pontosc == pontosf && Cs > Fs)
	{
		printf ("C\n");
	}

	if (pontosc == pontosf && Fs > Cs)
	{
		printf ("F\n");
	}
	if (pontosc == pontosf && Cs == Fs) // se a pontuação de C e F forem iguais
	{
		printf ("=\n"); //imprima =
	}
}
