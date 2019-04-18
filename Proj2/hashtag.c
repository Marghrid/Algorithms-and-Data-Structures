/* * * * * * * * * * * * * * * *
 *  IAED || PROJETO 2 		   *
 *  80832 Margarida Ferreira   *
 *	81805 Duarte David		   *
 * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtag.h"

// new_hashtag(texto) cria uma nova hashtag com uma string texto, passada por argumento;
hashtag* new_hashtag(char* text)
{
	hashtag* new = (hashtag*)malloc(sizeof(hashtag));
	
	int text_size = strlen(text);
	new->text = (char*)malloc(sizeof(char)*(text_size+1));
	strcpy(new->text, text);
	
	new->count = 1;
	
	return new;
}

// increase_hashtag(h_tag): incrementa o numero de ocorrencias da hashtag cuja morada e
//							h_tag;
void increase_hashtag(hashtag* h_tag)
{
	h_tag->count++;
}

// delete_hashtag(h_tag): libera a memoria ocupada pela hashtag cuja morada e h_tag;
void delete_hashtag(void* h_tag)
{
	free(((hashtag*)h_tag)->text);
	free((hashtag*)h_tag);
}

// print_hashtag(h_tag): imprime no standard output o texto e o numero de ocorrencias
//                       da hashtag cuja morada e h_tag;
void print_hashtag(void* h_tag)
{
	printf("#%s %d\n", ((hashtag*)h_tag)->text, ((hashtag*)h_tag)->count);
}

// As seguintes funcoes de comparacao retornam o seguinte:
//	   -1, se o primeiro argumento for menor;
//	    0, se os argumentos forem iguais;
//	   	1, se o primeiro argumento for maior;

// compare_hashtag_n_string(h_tag, texto): compara uma hashtag passada por referencia
//             (h_tag) e uma string (texto). A hashtag diz-se menor (resp. igual/maior)
//             do que a string se o seu texto for lexicograficamente menor
//             (resp. igual/maior) do que o texto na string;
int compare_hashtag_n_string(void* h_tag, void* text)
{
	return strcmp(((hashtag*)h_tag)->text, (char*)text);
}

// compare_hashtag(h_tag1, h_tag2): compara duas hashtags passadas por referencia,
//                                  com base na ordem pedida no comando l;
int compare_hashtag(const void* h_tag1,const void* h_tag2)
{
	if(((hashtag*)h_tag1)->count > ((hashtag*)h_tag2)->count)
		return -1;
	
	if(((hashtag*)h_tag1)->count < ((hashtag*)h_tag2)->count)
		return 1;
	
	return strcmp(((hashtag*)h_tag1)->text, ((hashtag*)h_tag2)->text);
}

// compare_hashtag_pointer(h_tag1, h_tag2): compara duas hashtags cuja morada e passada 
//                                          por referencia, com base na ordem pedida no
//										    comando l;
int compare_hashtag_pointer(const void* h_tag1,const void* h_tag2)
{
	return compare_hashtag(*(void**)h_tag1, *(void**)h_tag2);
}

// hash_string(texto, size):  funcao de dispersao de uma hashtag, que recebe uma string
//                            texto e um inteiro 'size' com o tamanho da hashtable;
int hash_string(void* string, int p)
{  
	// Implementacao da funcao djb2 de Bernstein, como descrita em
	// https://en.wikipedia.org/wiki/Universal_hashing#Hashing_strings
	int h = 5381, a = 33;

	while (*(char*)string != '\0') 
	{
		h = (a*h + *(char*)string) % p;
		string = (char*)string+1;
	}  
	return h; 
}

// hash_hashtag(h_tag, size): funcao de dispersao de uma hashtag, que recebe um ponteiro
//                            para uma hashtag (h_tag) e um inteiro com o tamanho da
//							  hashtable (size);
int hash_hashtag(void* h_tag, int p)
{
	return hash_string(((hashtag*)h_tag)->text, p);
}
