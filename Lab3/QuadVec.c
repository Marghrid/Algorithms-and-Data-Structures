#include <stdio.h>
#include "Lab3.h"

void quadVect(int *v, int n)
{
	int i;
	for (i=0; i<n; ++i)
		v[i] = v[i] * v[i];
}

int main()
{
	int n, k, pos;

	puts("\n\nQual o comprimento do vetor?");
	scanf("%d", &n);

	int v[n];

	puts("\nInsira o vetor:");	
	leVector(v, n);

	quadVect(v, n);
	puts("O vetor dos quadrados dos elementos do vetor original e:");
	escVector(v, n);

	printf("\n\n");

	return 0;
}