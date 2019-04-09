#include <stdio.h>

#define N 5

typedef struct{
	float valor;
	float txan;
}deposito;

deposito leDeposito();

void mostraDeposito(deposito);

void leVetorDepositos(deposito[N]);