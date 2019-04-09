#include <stdio.h>
#include "Lab3.h"

int somaVector (int *v, int n)
{
	int i, soma = 0;

	for (i = 0; i < n; ++i)
		soma += v[i];

	return soma;
}

int main()
{
	int n;

	puts("\n\nQuantos inteiros vai escrever?  ");
	scanf("%d", &n);

	int v[n];

	puts("\n Insira os inteiros: \n");	
	leVector(v, n);

	printf("\nA soma de todos os inteiros do vector e: %d\n\n", somaVector(v, n));

	return 0;
}