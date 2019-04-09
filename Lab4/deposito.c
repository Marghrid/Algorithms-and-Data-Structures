#include <stdio.h>
#include "deposito.h"

deposito leDeposito()
{
	float valor, txan;

	puts("Introduza um novo deposito:");
	printf("\tValor: ");
	scanf("%f", &valor);
	printf("\tTAN: ");
	scanf("%f", &txan);

	deposito depp = {valor, txan};
	return depp;
}

void mostraDeposito(deposito depp)
{
	printf("\tValor: %g\n", depp.valor);
	printf("\tTAN: %g\n", depp.txan);
}

void leVetorDepositos(deposito depositos[N])
{
	int i;
	for (i = 0; i<N; ++i)
		depositos[i] = leDeposito();
}

