/* * * * * * * * * * * * * * * *
 *  IAED || PROJETO 2 		   *
 *  80832 Margarida Ferreira   *
 *	81805 Duarte David		   *
 * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtag.h"

hashtag* new_hashtag(char* text)
{
	hashtag* new = (hashtag*)malloc(sizeof(hashtag));
	
	int text_size = strlen(text);
	new->text = (char*)malloc(sizeof(char)*(text_size+1));
	strcpy(new->text, text);
	
	new->count = 1;
	
	return new;
}

void increase_hashtag(hashtag* htag)
{
	htag->count++;
}

void delete_hashtag(void* htag)
{
	free(((hashtag*)htag)->text);
	free((hashtag*)htag);
}

void do_nothing(void* htag){}

void print_hashtag(void* htag)
{
	printf("#%s %d\n", ((hashtag*)htag)->text, ((hashtag*)htag)->count);
}

int compare_hashtag_n_string(void* h_tag, void* text)
{
	return strcmp(((hashtag*)h_tag)->text, (char*)text);
}

int compare_hashtag(void* h_tag1, void* h_tag2)
{
	if(((hashtag*)h_tag1)->count > ((hashtag*)h_tag2)->count)
		return -1;
	
	if(((hashtag*)h_tag1)->count < ((hashtag*)h_tag2)->count)
		return 1;
	
	return strcmp(((hashtag*)h_tag1)->text, ((hashtag*)h_tag2)->text);
}

int compare_hashtag_pointer(const void* h_tag1,const void* h_tag2)
{
	return compare_hashtag(*(void**)h_tag1, *(void**)h_tag2);
}

int hash_string(void* string, int p)
{  
	//esta e uma implementacao da funcao djb2 de Bernstein, descrita em
	//https://en.wikipedia.org/wiki/Universal_hashing#Hashing_strings
	int h = 5381, a = 33; 
	while (*(char*)string != '\0') 
	{
		h = (a*h + *(char*)string) % p;
		string = (char*)string+1;
	}  
	return h; 
}

int hash_hashtag(void* h_tag, int p)
{
	return hash_string(((hashtag*)h_tag)->text, p);
}
