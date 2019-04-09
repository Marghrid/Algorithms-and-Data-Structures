 /* * * * * * * * * * * * * * * *
  *  IAED || PROJETO 1 			*
  *  Duarte David, 81805		*
  *  Margarida Ferreira, 80832	*
  * * * * * * * * * * * * * * * */
  
/* comandos.c: 
 *		Definicao das funcoes declaradas em "comandos.h";
 */

#include <stdio.h>
#include <string.h>
#include "base_dados.h"
#include "comandos.h"

void executa_A (base_dados* base_atual)
{
	char id[4];
	int capacidade;
	int i;
	
	scanf("%s %d", id, &capacidade);
	
	// Inicializacao em base_atual dos dados referentes ao novo aeroporto:
	strcpy(base_atual->aeroportos[base_atual->n_aeroportos].id, id);
	base_atual->aeroportos[base_atual->n_aeroportos].estado = ABERTO;
	base_atual->aeroportos[base_atual->n_aeroportos].capacidade = capacidade;
	base_atual->n_aeroportos++;
	
	for (i=0; i < base_atual->n_aeroportos; i++)
	{
		base_atual->voos[i][base_atual->n_aeroportos] = 0;
		base_atual->voos[base_atual->n_aeroportos][i] = 0;
	}
}

void executa_I(base_dados* base_atual)
{
	char id[4];
	int capacidade;
	int i;

	scanf("%s %d", id, &capacidade);
	
	i = procura_aeroporto(base_atual->aeroportos, id, base_atual->n_aeroportos);
	
	// Caso nao se verifique que
	//	(1) O aeroporto existe;
	//	(2) O aeroporto nao esta encerrado;
	//	(3) A capacidade nao sera inferior ao numero total de voos com origem e destino no aeroporto;
	// imprime 'string' de erro;
	if( i == INEXISTENTE ||  base_atual->aeroportos[i].estado == ENCERRADO 
	    || (base_atual->aeroportos[i].capacidade + capacidade < conta_voos_total(base_atual->voos, i, base_atual->n_aeroportos))
	  )
		printf("*Capacidade de %s inalterada\n", id);
	else
		base_atual->aeroportos[i].capacidade += capacidade;
}

void executa_F (base_dados* base_atual)
{
	char id_1[4], id_2[4];
	int aeroporto1, aeroporto2;

	scanf("%s %s", id_1, id_2);

	aeroporto1 = procura_aeroporto(base_atual->aeroportos, id_1, base_atual->n_aeroportos);
	aeroporto2 = procura_aeroporto(base_atual->aeroportos, id_2, base_atual->n_aeroportos);

	// Caso nao se verifique que
	//	(1) Os aeroportos existem;
	//	(2) Os aeroportos nao estao encerrados;
	//	(3) O numero de total de voos com origem e destino nos aeroportos nao excedera a capacidade dos mesmos;
	// imprime 'string' de erro;	
	if ( aeroporto1 == INEXISTENTE || aeroporto2 == INEXISTENTE
		 || base_atual->aeroportos[aeroporto1].estado == ENCERRADO
		 || base_atual->aeroportos[aeroporto2].estado == ENCERRADO
		 || base_atual->aeroportos[aeroporto1].capacidade < (conta_voos_total(base_atual->voos, aeroporto1, base_atual->n_aeroportos)+2)
		 || base_atual->aeroportos[aeroporto2].capacidade < (conta_voos_total(base_atual->voos, aeroporto2, base_atual->n_aeroportos)+2)
	   )
		printf("*Impossivel adicionar voo RT %s %s\n", id_1, id_2);
	else
		adiciona_voo_ida_volta(base_atual->voos, aeroporto1, aeroporto2);
}


void executa_G (base_dados* base_atual)
{
	char id_1[4], id_2[4];
	int origem, destino;

	scanf("%s %s", id_1, id_2);

	origem = procura_aeroporto(base_atual->aeroportos, id_1, base_atual->n_aeroportos);
	destino = procura_aeroporto(base_atual->aeroportos, id_2, base_atual->n_aeroportos);
	
	// Caso nao se verifique que
	//	(1) Os aeroportos existem;
	//	(2) Os aeroportos nao estao encerrados;
	//	(3) O numero de total de voos com origem e destino nos aeroportos nao excedera a capacidade dos mesmos;
	// imprime 'string' de erro;
	if ( origem == INEXISTENTE || destino == INEXISTENTE
		 || base_atual->aeroportos[origem].estado == ENCERRADO
		 || base_atual->aeroportos[destino].estado == ENCERRADO
		 || base_atual->aeroportos[origem].capacidade == conta_voos_total(base_atual->voos, origem, base_atual->n_aeroportos)
		 || base_atual->aeroportos[destino].capacidade == conta_voos_total(base_atual->voos, destino, base_atual->n_aeroportos)
	   )
		printf("*Impossivel adicionar voo %s %s\n", id_1, id_2);
	else
		adiciona_voo(base_atual->voos, origem, destino);
}

void executa_R (base_dados* base_atual)
{
	char id_1[4], id_2[4];
	int origem, destino;

	scanf("%s %s", id_1, id_2);

	origem = procura_aeroporto(base_atual->aeroportos, id_1, base_atual->n_aeroportos);
	destino = procura_aeroporto(base_atual->aeroportos, id_2, base_atual->n_aeroportos);
	
	// Caso nao se verifique que
	//	(1) Os aeroportos existem;
	//	(2) O numero de total de voos com origem e destino nos aeroportos e diferente de 0 (quando estao encerrados, e 0);
	// imprime 'string' de erro;
	if (origem == INEXISTENTE || destino == INEXISTENTE ||  !conta_voos_ida_entre(base_atual->voos, origem, destino))
		printf("*Impossivel remover voo %s %s\n", id_1, id_2);
	else
		remove_voo(base_atual->voos, origem, destino);
}

void executa_S (base_dados* base_atual)
{
	char id_1[4], id_2[4];
	int aeroporto1, aeroporto2;

	scanf("%s %s", id_1, id_2);

	aeroporto1 = procura_aeroporto(base_atual->aeroportos, id_1, base_atual->n_aeroportos);
	aeroporto2 = procura_aeroporto(base_atual->aeroportos, id_2, base_atual->n_aeroportos);
	
	// Caso nao se verifique que
	//	(1) Os aeroportos existem;
	//	(2) Existe pelo menos um voo de ida e volta entre os aeroportos (nao existe quando estao encerrados);
	// imprime 'string' de erro;
	if ( aeroporto1 == INEXISTENTE || aeroporto2 == INEXISTENTE
		 || !conta_voos_ida_entre(base_atual->voos, aeroporto1, aeroporto2)
		 || !conta_voos_ida_entre(base_atual->voos, aeroporto2, aeroporto1)
	   )
		printf("*Impossivel remover voo RT %s %s\n", id_1, id_2);
	else
		remove_voo_ida_volta(base_atual->voos, aeroporto1, aeroporto2);
}

void executa_N(base_dados* base_atual)
{
	char id_1[4], id_2[4];
	int origem, destino;
	
	scanf("%s %s", id_1, id_2);

	origem = procura_aeroporto(base_atual->aeroportos, id_1, base_atual->n_aeroportos);
	destino = procura_aeroporto(base_atual->aeroportos, id_2, base_atual->n_aeroportos);
	
	if(origem == INEXISTENTE)
		printf("*Aeroporto %s inexistente\n", id_1);
		
	if(destino == INEXISTENTE)								// Nao tem um else (antes do if) para que sejam impressas 2 strings 
		printf("*Aeroporto %s inexistente\n", id_2);		//  de erro caso nenhum dos aeroportos exista;
	
	else if(origem != INEXISTENTE)
		printf( "Voos entre cidades %s:%s:%d:%d\n", id_1, id_2,
				conta_voos_ida_entre(base_atual->voos, origem, destino),
				conta_voos_ida_entre(base_atual->voos, destino, origem)
			  );
}

void executa_P(base_dados* base_atual)
{
	int i,  voos_contados, max = 0, voos_max = conta_voos_total(base_atual->voos, 0, base_atual->n_aeroportos);
	
	for(i=1; i < (base_atual->n_aeroportos); i++)
	{
		voos_contados = conta_voos_total(base_atual->voos, i, base_atual->n_aeroportos);
		
		if(voos_contados > voos_max)
		{
			voos_max = voos_contados;
			max = i;
		}
	}
	
	printf( "Aeroporto com mais rotas %s:%d:%d\n", base_atual->aeroportos[max].id,
			conta_voos_ida(base_atual->voos, max, base_atual->n_aeroportos),
			conta_voos_volta(base_atual->voos, max, base_atual->n_aeroportos)
		  );	
}

void executa_Q(base_dados* base_atual)
{
	
	int i, max = 0, ligacoes_max = conta_ligacoes(base_atual->voos, 0, base_atual->n_aeroportos), ligacoes_contadas;
	
	for(i=1; i < (base_atual->n_aeroportos); i++)
	{
		ligacoes_contadas = conta_ligacoes(base_atual->voos, i, base_atual->n_aeroportos);
		
		if(ligacoes_contadas > ligacoes_max)
		{
			ligacoes_max = ligacoes_contadas;
			max = i;
		}
	}
	
	printf("Aeroporto com mais ligacoes %s:%d\n", base_atual->aeroportos[max].id, ligacoes_max);
}

void executa_V(base_dados* base_atual)
{
	int i, j, novo_voo, voo_max = -1, max_origem = -1, max_destino = -1;

	for(i=0; i < (base_atual->n_aeroportos); i++)
	{
		for (j=0; j < (base_atual->n_aeroportos); j++)
		{
			novo_voo = conta_voos_ida_entre(base_atual->voos, i, j);
			
			if(novo_voo > voo_max)
			{
				voo_max = novo_voo;
				max_origem = i;
				max_destino = j;
			}
		}
	}
	
	printf("Voo mais popular %s:%s:%d\n", base_atual->aeroportos[max_origem].id, base_atual->aeroportos[max_destino].id, voo_max);
}

void executa_C(base_dados* base_atual)
{
	int aeroporto, i;
	char id[4];

	scanf("%s", id);
	aeroporto = procura_aeroporto(base_atual->aeroportos, id, base_atual->n_aeroportos);

	if (aeroporto == INEXISTENTE)
		printf("*Aeroporto %s inexistente\n", id);
	
	else
	{
		base_atual->aeroportos[aeroporto].estado = ENCERRADO;
		
		// Coloca todos os voos de/para esse aeroporto a 0:
		for (i=0; i < base_atual->n_aeroportos; i++)
		{
			base_atual->voos[i][aeroporto] = 0;
			base_atual->voos[aeroporto][i] = 0;
		}
	}
}

void executa_O (base_dados* base_atual)
{
	int aeroporto;
	char id[4];

	scanf("%s", id);
	
	aeroporto = procura_aeroporto(base_atual->aeroportos, id, base_atual->n_aeroportos);

	if (aeroporto == INEXISTENTE)
		printf("*Aeroporto %s inexistente\n", id);
	else
		base_atual->aeroportos[aeroporto].estado = ABERTO;
}

void executa_L (base_dados* base_atual)
{
	int i, tipo;
	int indices[MAX_AEROPORTOS];
	int histograma[MAX_VOOS + 1] = {0}, n_max_voos = 0, voos_contados;
	
	scanf("%d", &tipo);
	
	switch (tipo)		// Escolhe a listagem a ser feita;
	{
		case 0:			// Listagem dos aeroportos pela ordem que foram adicionados ao sistema:
			for (i=0; i < base_atual->n_aeroportos; ++i)
				imprime_aeroporto(base_atual, i);
			break;
		
		case 1:			// Listagem dos aeroportos por ordem alfabetica:
			for(i=0; i < base_atual->n_aeroportos; i++)
				indices[i] = i;
			
			ordenaAeroportos(indices, base_atual->aeroportos, 0, base_atual->n_aeroportos-1);
			
			for (i=0; i < base_atual->n_aeroportos; ++i)
				imprime_aeroporto(base_atual, indices[i]);

			break;
			
		case 2:			// Imprime um histograma da frequencia de aeroportos com x voos, na forma 'x:n_aeroportos':
			for(i=0; i < base_atual->n_aeroportos; i++)
			{	
				voos_contados = conta_voos_total(base_atual->voos, i, base_atual->n_aeroportos);
				histograma[voos_contados]++;
				
				if(n_max_voos < voos_contados)
					n_max_voos = voos_contados;
			}
			
			for(i=0; i <= n_max_voos; i++)
				if(histograma[i])
					printf("%d:%d\n", i, histograma[i]);
			
			break;

		default:
			printf("*Tipo de listagem desconhecido\n");
	}
}

void executa_X (base_dados* base_atual)
{
	printf("%d:%d\n", conta_voos(base_atual->voos, base_atual->n_aeroportos), base_atual->n_aeroportos);
}