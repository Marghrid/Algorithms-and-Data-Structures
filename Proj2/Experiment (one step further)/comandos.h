/* * * * * * * * * * * * * * * *
 *  IAED || PROJETO 2 		   *
 *  80832 Margarida Ferreira   *
 *	81805 Duarte David		   *
 * * * * * * * * * * * * * * * */
 
#ifndef __COMANDOS__
#define __COMANDOS__

#include "AVL.h"
#include "hashtag.h"
#include "hashtable.h"

// 'data': estrutura cuja instancia guardara todos 
//         os dados necessarios para a execucao do programa.
typedef struct
{
	avl_link hashtag_tree;
	hashtable* htable;
	int hashtags_total;
	int hashtags_different;
	hashtag* best_htag;
} data;

//funcoes responsaveis pela execucao dos respetivos comandos:
void executa_a(data*);
void executa_s(data*);
void executa_m(data*);
void executa_l(data*);
void executa_x(data*);

// split_n_process(texto, dados): divide uma string 'texto' em palavras,
//                                e processa essas palavras, caso sejam #hashtags,
//                                colocando-as na estrutura de dados 'dados';
void split_n_process(char*, data*);

// add_hashtag(texto, dados): adiciona uma hashtag com o texto 'texto'
//                            a estrutura de dados 'dados';
void add_hashtag(char*, data*);

#endif