#include <stdio.h>
#include "deposito.h"

int main()
{
	deposito depositos[N];
	int i;
	float soma = 0;

	leVetorDepositos(depositos);

	for (i = 0; i<N; ++i)
		soma += depositos[i].valor;

	printf("Soma dos valores depositados: %g\n", soma);

	return 0;
}