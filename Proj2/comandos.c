/* * * * * * * * * * * * * * * *
 *  IAED || PROJETO 2 		   *
 *  80832 Margarida Ferreira   *
 *	81805 Duarte David		   *
 * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "comandos.h"

#define NUMSEP 11
#define MAXLINESIZE 141
static const char separators[] = {' ','\t',',',';','.','?','!','"','\n',':','\0'};

// split_n_process(texto, dados): divide uma string 'texto' em palavras,
//                                e processa essas palavras, caso sejam #hashtags,
//                                colocando-as na estrutura de dados 'dados';
void split_n_process(char *line, data* current_data )
{
	int i, j, k;
	char buffer[MAXLINESIZE];
	for(i = 0, k = 0; line[i] != '\0'; i++, k++) 
	{
		buffer[k] = tolower(line[i]);
		for(j = 0; j < NUMSEP; j++) 
		{
			if(line[i] == separators[j]) 
			{
				if(k != 0) 
				{
					buffer[k] = '\0';
					if(buffer[0]=='#' && buffer[1]!='\0')
						add_hashtag(buffer+1, current_data);
				}
				k = -1;
			}
		}
	}
}


// add_hashtag(texto, dados): adiciona uma hashtag com o texto 'texto'
//                            a estrutura de dados 'dados';
void add_hashtag(char* text, data* current_data)
{
	current_data->hashtags_total++;
	hashtag* h_tag =
		ht_search(current_data->htable, text, compare_hashtag_n_string, hash_string);

	if (!h_tag)
	{
		h_tag = new_hashtag(text);
		ht_insert(&(current_data->htable), (void*)h_tag, hash_hashtag);
		current_data->hashtags_different++;
	}

	else
		increase_hashtag(h_tag);
	
	// Compara h_tag com a best_htag atual e ve se esta deve ser substituida.
	if (!current_data->best_htag ||
		compare_hashtag((void*)h_tag, current_data->best_htag) < 0)

		current_data->best_htag = h_tag;
}

// Funcoes responsaveis pela execucao dos respetivos comandos:

// executa_a(dados): Processa uma mensagem incrementando para cada hashtag
//                   encontrada o contador respectivo;
void executa_a(data* current_data)
{
	char line[MAXLINESIZE];

	fgets(line, MAXLINESIZE, stdin);
	split_n_process(line, current_data);
}

// executa_s(dados): Mostra o número de hashtags distintas e o número total
//                   ocorrências de todas as hashtags;
void executa_s(data* current_data)
{
	printf("%d %d\n", current_data->hashtags_different, 
					 current_data->hashtags_total
					 );
}

// executa_m(dados): Mostra a hashtag mais popular;
void executa_m(data* current_data)
{	
	if(current_data->best_htag)
		print_hashtag(current_data->best_htag);
}

// executa_l(dados): Lista todas as hashtags por ordem decrescente do número
//                   de ocorrências. Em caso de igualdade, as hashtags
//                   deverão ser ordenadas alfabeticamente;
void executa_l(data* current_data)
{
	int i;
	
	// Guardam-se ponteiros para as hashtags em memoria num array
	// temporario, para ser ordenado e impresso.
	hashtag** tmp_array =
		(hashtag**)malloc(sizeof(hashtag*) * current_data->hashtags_different);
	ht_to_array(current_data->htable, (void**)tmp_array);
	
	qsort((void*)tmp_array, current_data->hashtags_different,
		  sizeof(hashtag*), compare_hashtag_pointer);
		   
	for(i=0; i < current_data->hashtags_different; i++)
		print_hashtag(tmp_array[i]);

	free(tmp_array);
}

// executa_x(dados): Termina o programa;
void executa_x(data* current_data)
{
	ht_free(current_data->htable, delete_hashtag);
}
