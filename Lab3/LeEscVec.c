#include <stdio.h>
#include "Lab3.h"

int main()
{
	int n;

	puts("\n\nQuantos inteiros vai escrever?  ");
	scanf("%d", &n);

	int v[n];

	puts("\n Insira os inteiros: \n");	
	leVector(v, n);
	puts("\n Os inteiros inseridos foram:");
	escVector(v, n);

	printf("\n\n");

	return 0;

}