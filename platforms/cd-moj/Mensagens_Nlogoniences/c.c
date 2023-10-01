#include<stdio.h>
#include<stdlib.h>

typedef struct elemento
{
	int chave;
	int valor;
} elemento;

elemento *tabelaHash;

void criarTabelaHash(int tamTabelaHash){
	int aux;
	tabelaHash = malloc(sizeof(elemento) * (size_t)tamTabelaHash);

	for(aux = 0; aux < tamTabelaHash; aux++){             // as chaves maiores ou iguais a zero sao validas
		tabelaHash[aux].chave = -1;
	}

}

int buscarNaTabela(int chave, int tamanho){
	int codigoHash = hash(chave, tamanho);
	while(tabelaHash[codigoHash].chave != -1){
		if(tabelaHash[codigoHash].chave == chave){
			return codigoHash;
		}
		else{
			codigoHash = (codigoHash + 1) % tamanho;
		}
	}

	return -1;

}

void insereNaTabela(int chave, int valor, int tamTabelaHash){
	int codigoHash = hash(chave, tamTabelaHash);
	while(tabelaHash[codigoHash].chave != -1){
		codigoHash = (codigoHash + 1) % tamTabelaHash;
	}
	tabelaHash[codigoHash].chave = chave;
	tabelaHash[codigoHash].valor = valor;
}

int main(){
	int aux, chave, tamTabelaHash = 2000003, busca, valor;
	char caractere;
	criarTabelaHash(tamTabelaHash);
	while(scanf("%d %c", &chave, &caractere) != EOF){
		busca = buscarNaTabela(chave, tamTabelaHash);
		if(busca == -1){
			valor = caractere;
			insereNaTabela(chave, valor, tamTabelaHash);
		}
	}

	heapSort(tamTabelaHash);

	for(aux = 0; aux < tamTabelaHash; aux++){
		if(tabelaHash[aux].valor >= 33 && tabelaHash[aux].valor <= 126){
			printf("%c", tabelaHash[aux].valor);
		}
	}

	printf("\n");

	free(tabelaHash);

	return 0;
}
