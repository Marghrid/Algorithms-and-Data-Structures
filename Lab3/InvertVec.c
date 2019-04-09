#include <stdio.h>
#include "Lab3.h"

void invertVector(int *v, int n)
{
	int i, aux;
	for (i = 0; i < n/2; ++i)
	{
		aux = v[i];
		v[i] = v[n-i-1];
		v[n-i-1] = aux;
	}
}

int main()
{
	int n;

	puts("\n\nQual o comprimento do vetor?");
	scanf("%d", &n);

	int v[n];

	puts("\nInsira o vetor:");	
	leVector(v, n);

	invertVector(v, n);

	puts("O vetor resultante da inversao do vetor original e:");
	escVector(v, n);

	puts("\n");

	return 0;
}