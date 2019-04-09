#include <stdio.h>
#include "Lab3.h"

int posMax (int *v, int n)
{
	int i, pos_max = 0;
	for(i = 1; i < n; ++i)
		if (v[i] > v[pos_max])
			pos_max = i;

	return pos_max + 1;
}

int posMin (int *v, int n)
{
	int i, pos_min = 0;
	for(i = 1; i < n; ++i)
		if (v[i] < v[pos_min])
			pos_min = i;

	return pos_min + 1;
}

int main()
{

	int n;

	puts("\n\nQual o comprimento do vetor?");
	scanf("%d", &n);

	int v[n];

	puts("\n Insira o vetor:");	
	leVector(v, n);

	printf("\nO maior elemento deste vetor e o %do e o menor e o %do\n\n", posMax(v, n), posMin(v, n) );

	return 0;

}