 /* * * * * * * * * * * * * * * *
  *  IAED || PROJETO 1 			*
  *  Duarte David, 81805		*
  *  Margarida Ferreira, 80832	*
  * * * * * * * * * * * * * * * */
  
/* base_dados.c: 
 *		Definicao das funcoes declaradas em "base_dados.h";
 */
  
#include <stdio.h>
#include <string.h>
#include "base_dados.h"

int procura_aeroporto(aeroporto aeroportos[], char id[], int n_aeroportos)
{
	int i = 0;

	while(i < n_aeroportos && strcmp(aeroportos[i].id, id))
		i++;

	if (i == n_aeroportos)
		return INEXISTENTE;
	
	return i;
}

int conta_voos_ida_entre(unsigned int voos[][MAX_AEROPORTOS], int origem, int destino)
{
	return voos[origem][destino];
}

int conta_voos_ida(unsigned int voos[][MAX_AEROPORTOS], int origem, int n_aeroportos)
{
	int i, soma = 0;

	for(i=0; i < n_aeroportos; i++)
		soma+=voos[origem][i];		// Nao se descontam as posicoes na diagonal da matriz (ou seja o numero de voos com
									//  origem e destino no mesmo aeroporto) porque se assume que estao sempre a zero.
	return soma;
}

int conta_voos_volta(unsigned int voos[][MAX_AEROPORTOS], int destino, int n_aeroportos)
{
	int i, soma = 0;

	for(i=0; i < n_aeroportos; i++)
		soma += voos[i][destino];	// Nao se descontam as posicoes na diagonal da matriz (ou seja o numero de voos com
									//  origem e destino no mesmo aeroporto) porque se assume que estao sempre a zero.
	return soma;
}

int conta_voos_entre(unsigned int voos[][MAX_AEROPORTOS], int aeroporto1, int aeroporto2)
{
	return voos[aeroporto1][aeroporto2] + voos[aeroporto2][aeroporto1];
}

int conta_voos_total(unsigned int voos[][MAX_AEROPORTOS], int aeroporto, int n_aeroportos)
{
	return conta_voos_volta(voos, aeroporto, n_aeroportos) + conta_voos_ida(voos, aeroporto, n_aeroportos);
}

int conta_voos(unsigned int voos[][MAX_AEROPORTOS], int n_aeroportos)
{
	int i, soma = 0;

	for (i=0; i < n_aeroportos; i++)
		soma += conta_voos_ida(voos, i, n_aeroportos);

	return soma;
}

int conta_ligacoes(unsigned int voos[][MAX_AEROPORTOS], int aeroporto, int n_aeroportos)
{
	int i, soma = 0;

	for(i = 0; i < n_aeroportos; i++)
		if(i != aeroporto && (voos[i][aeroporto] != 0 || voos[aeroporto][i] != 0) )
			soma++;

	return soma;
}

void adiciona_voo(unsigned int voos[][MAX_AEROPORTOS], int origem, int destino)
{
	voos[origem][destino]++;
}

void remove_voo(unsigned int voos[][MAX_AEROPORTOS], int origem, int destino)
{
	voos[origem][destino]--;
}

void adiciona_voo_ida_volta(unsigned int voos[][MAX_AEROPORTOS], int aeroporto1, int aeroporto2)
{
	adiciona_voo(voos, aeroporto1, aeroporto2);
	adiciona_voo(voos, aeroporto2, aeroporto1);
}

void remove_voo_ida_volta(unsigned int voos[][MAX_AEROPORTOS], int aeroporto1, int aeroporto2)
{
	remove_voo(voos, aeroporto1, aeroporto2);
	remove_voo(voos, aeroporto2, aeroporto1);
}

void imprime_aeroporto(base_dados* base_atual, int aeroporto)
{
	printf( "%s:%d:%d:%d\n", base_atual->aeroportos[aeroporto].id, base_atual->aeroportos[aeroporto].capacidade,
			conta_voos_ida(base_atual->voos, aeroporto, base_atual->n_aeroportos),
			conta_voos_volta(base_atual->voos, aeroporto, base_atual->n_aeroportos)
		  );
}

void ordenaAeroportos(int indices[], aeroporto aeroportos[], int esquerda, int direita)
{
	int i;
	
	if (direita <= esquerda)
		return;

	i = particaoAeroportos(indices, aeroportos, esquerda, direita);
	ordenaAeroportos(indices, aeroportos, esquerda, i-1);
	ordenaAeroportos(indices, aeroportos, i+1, direita);
}

int particaoAeroportos(int indices[], aeroporto aeroportos[], int esquerda, int direita)
{
	int tmp, pivot = indices[direita], i = esquerda - 1,  j = direita;

	while(i<j)
	{
		while(strcmp(aeroportos[indices[++i]].id, aeroportos[pivot].id) < 0);
		while(strcmp(aeroportos[pivot].id, aeroportos[indices[--j]].id) < 0)
			if(j == esquerda)
				break;

		if(i<j)
		{
			tmp = indices[i];
			indices[i] = indices[j];
			indices[j] = tmp;			
		}
	}
	tmp = indices[i];
	indices[i] = indices[direita];
	indices[direita] = tmp;
	
	return i;
}