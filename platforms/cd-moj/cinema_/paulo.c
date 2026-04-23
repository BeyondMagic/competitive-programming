#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char letters[] = {'X','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'};

int findLetter(char ch) {

	for(int i = 1; i < 21; ++i)
		if(letters[i] == ch)
			return i;

	return -1;
}

int charToDigit(int n) {
	return n - '0';
}

int main(void) {

	int r,c;
	scanf("%d %d", &r,&c);
	int matrix[r+1][c+1];

	char code[3];

	for(int i = 0; i <= r; ++i)
		for(int j = 0; j <= c; ++j)
			matrix[i][j] = 0;

	while (scanf("%s", code) != EOF)
	{
		if(r >= 10 || c >= 10) {
			matrix[findLetter(code[0])][(charToDigit(code[1]) * 10) + (charToDigit(code[2]))] = 1;
			//printf("%d\n",matrix[findLetter(code[0])][(charToDigit(code[1]) * 10) + (charToDigit(code[2]))]);
		}
		else {
			matrix[findLetter(code[0])][charToDigit(code[1])] = 1;
			//printf("%d\n",matrix[findLetter(code[0])][charToDigit(code[1])] = 1);
		}

	}

	printf("  ");

	for(int i = 1; i <= c; ++i)
		printf("%02d%s", i, i == c ? "" : " ");
	printf("\n");

	for(int i = r; i > 0; --i) {
		printf("%c ", letters[i]);
		for(int j = 1; j <= c; ++j) {
			if(matrix[i][j] == 1)
				printf("XX");
			else
				printf("--");

			printf(j == c ? "\n" : " ");
		}
	}

}
