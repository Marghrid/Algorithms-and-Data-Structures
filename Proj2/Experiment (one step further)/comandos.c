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


void executa_a(data* current_data)
{
	char line[MAXLINESIZE];

	fgets(line, MAXLINESIZE, stdin);
	split_n_process(line, current_data);
}


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


void add_hashtag(char* text, data* current_data)
{
	current_data->hashtags_total++;
	hashtag* htag = ht_search(current_data->htable, text, compare_hashtag_n_string, hash_string);
	if (!htag)
	{
		htag = new_hashtag(text);
		ht_insert(&(current_data->htable), (void*)htag, hash_hashtag);
		avl_insert(&(current_data->hashtag_tree), (void*)htag, compare_hashtag);
		balance_avl(&(current_data->hashtag_tree));
		current_data->hashtags_different++;
	}
	else
	{
		avl_delete(&(current_data->hashtag_tree), htag, compare_hashtag, do_nothing);
	    htag->count++;
		avl_insert(&(current_data->hashtag_tree), (void*)htag, compare_hashtag);
		balance_avl(&(current_data->hashtag_tree));
	}
	
	//compara com a best_htag atual e ve se e melhor
	if (!current_data->best_htag || 
		compare_hashtag( (void*)htag, current_data->best_htag) < 0)
		current_data->best_htag = htag;
}

void executa_s(data* current_data)
{
	printf("%d %d\n", current_data->hashtags_different, 
					 current_data->hashtags_total
					 );
}

void executa_m(data* current_data)
{	
	if(current_data->best_htag)
		print_hashtag(current_data->best_htag);
}




void executa_l(data* current_data)
{
	avl_sort(current_data->hashtag_tree, print_hashtag);
}

void executa_x(data* current_data)
{
	ht_free(current_data->htable, delete_hashtag);
	avl_free(current_data->hashtag_tree, do_nothing);
}
