#include <stdio.h>
#include "Lab3.h"

int procura(int *v, int n, int k)
{
	int i;

	for (i = 0; i < n; ++i)
		if (v[i] == k)
			return i + 1;
	return -1;
}

int main()
{
	int n, k, pos;

	puts("\n\nQual o comprimento do vetor?");
	scanf("%d", &n);

	int v[n];

	puts("\nInsira o vetor:");	
	leVector(v, n);

	puts("\nQual o elemento que deseja procurar no vetor?");
	scanf("%d", &k);

	if ((pos = procura(v, n, k)) == -1)
		printf("\nNao ha nenhuma ocorrencia do elemento %d no vetor", k);
	else
		printf("\nO elemento %d ocorre pela primeira vez na %da posicao do vetor", k, pos);

	printf("\n\n");

	return 0;
}