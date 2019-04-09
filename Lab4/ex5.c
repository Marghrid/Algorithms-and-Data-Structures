#include <stdio.h>
#include "deposito.h"

int main()
{
	deposito depp = leDeposito();
	printf("Valor liquido dos juros: %g\n", (depp.txan * depp.valor) * 0.79);
	return 0;
}