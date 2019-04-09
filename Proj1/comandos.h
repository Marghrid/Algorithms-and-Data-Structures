/* * * * * * * * * * * * * * * *
 *  IAED || PROJETO 1 		   *
 *  80832 Margarida Ferreira   *
 *	81805 Duarte David		   *
 * * * * * * * * * * * * * * * */
 
/* base_dados.c: 
 *		Declaracao das funcoes responsaveis pela execucao de cada um dos comandos;
 */

#ifndef COMANDOS
#define COMANDOS

#include "base_dados.h"

void executa_A(base_dados*);	// Adiciona um aeroporto a base de dados;
void executa_I(base_dados*);	// Altera a capacidade de um aeroporto na base de dados;
void executa_F(base_dados*);	// Adiciona um voo de ida e volta entre dois aeroportos;
void executa_G(base_dados*);	// Adiciona um voo so de ida entre dois aeroportos;
void executa_R(base_dados*);	// Remove um voo ja existente na base de dados;
void executa_S(base_dados*);	// Remove um voo de ida e volta ja existente na base de dados;
void executa_N(base_dados*);	// Imprime o numero total de voos entre dois aeroportos (em ambos os sentidos);
void executa_P(base_dados*);	// Imprime o ID do aeroporto com o maior numero de voos (partidas + chegadas);
void executa_Q(base_dados*);	// Imprime o ID do aeroporto com conexao a mais aeroportos;
void executa_V(base_dados*);	// Imprime os IDs dos aeroportos de origem e destino do voo mais frequente, bem como a sua frequencia;
void executa_C(base_dados*);	// Encerra um aeroporto existente na base de dados;
void executa_O(base_dados*);	// Reabre um aeroporto previamente encerrado;
void executa_L(base_dados*);	// Emite uma listagem dependendo do comando introduzido;
void executa_X(base_dados*);	// Sai do programa, imprimindo o numero de voos e aeroportos atualmente no sistema;

#endif