/* * * * * * * * * * * * * * * *
 *  IAED || PROJETO 2 		   *
 *  80832 Margarida Ferreira   *
 *	81805 Duarte David		   *
 * * * * * * * * * * * * * * * */
 
#ifndef __COMANDOS__
#define __COMANDOS__

#include "hashtag.h"
#include "hashtable.h"

// 'data': estrutura cuja instancia guardara todos os dados necessarios
//         para a execucao do programa;
typedef struct
{
	hashtable* htable;
	int hashtags_total;
	int hashtags_different;
	hashtag* best_htag;
} data;

// split_n_process(texto, dados): divide uma string 'texto' em palavras,
//                                e processa essas palavras, caso sejam #hashtags,
//                                colocando-as na estrutura de dados 'dados';
void split_n_process(char*, data*);

// add_hashtag(texto, dados): adiciona uma hashtag com o texto 'texto'
//                            a estrutura de dados 'dados';
void add_hashtag(char*, data*);

// Funcoes responsaveis pela execucao dos respetivos comandos:

// executa_a(dados): Processa uma mensagem incrementando para cada hashtag
//                   encontrada o contador respectivo;
void executa_a(data*);

// executa_s(dados): Mostra o número de hashtags distintas e o número total
//                   ocorrências de todas as hashtags;
void executa_s(data*);

// executa_m(dados): Mostra a hashtag mais popular;
void executa_m(data*);

// executa_l(dados): Lista todas as hashtags por ordem decrescente do número
//                   de ocorrências. Em caso de igualdade, as hashtags
//                   deverão ser ordenadas alfabeticamente;
void executa_l(data*);

// executa_x(dados): Termina o programa;
void executa_x(data*);

#endif
