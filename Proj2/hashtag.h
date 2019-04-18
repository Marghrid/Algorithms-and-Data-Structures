/* * * * * * * * * * * * * * * *
 *  IAED || PROJETO 2 		   *
 *  80832 Margarida Ferreira   *
 *	81805 Duarte David		   *
 * * * * * * * * * * * * * * * */
 
#ifndef __HASHTAG__
#define __HASHTAG__

// 'hashtag': estrutura que guarda o texto da hashtag
//            e o seu numero de ocorrencias.
typedef struct
{
	char *text;
	int count;
} hashtag; 

// new_hashtag(texto) cria uma nova hashtag com uma string texto, passada por argumento;
hashtag* new_hashtag(char*);

// increase_hashtag(h_tag): incrementa o numero de ocorrencias da hashtag cuja morada e
//							h_tag;
void increase_hashtag(hashtag*);

// delete_hashtag(h_tag): libera a memoria ocupada pela hashtag cuja morada e h_tag;
void delete_hashtag(void*);

// print_hashtag(h_tag): imprime no standard output o texto e o numero de ocorrencias
//                       da hashtag cuja morada e h_tag;
void print_hashtag(void*);


// As seguintes funcoes de comparacao retornam o seguinte:
//	   -1, se o primeiro argumento for menor;
//	    0, se os argumentos forem iguais;
//	   	1, se o primeiro argumento for maior;

// compare_hashtag_n_string(h_tag, texto): compara uma hashtag passada por referencia
//             (h_tag) e uma string (texto). A hashtag diz-se menor (resp. igual/maior)
//             do que a string se o seu texto for lexicograficamente menor
//             (resp. igual/maior) do que o texto na string;
int compare_hashtag_n_string(void*, void*);

// compare_hashtag(h_tag1, h_tag2): compara duas hashtags passadas por referencia,
//                                  com base na ordem pedida no comando l;
int compare_hashtag(const void*, const void*);

// compare_hashtag_pointer(h_tag1, h_tag2): compara duas hashtags cuja morada e passada 
//                                          por referencia, com base na ordem pedida no
//										    comando l;
int compare_hashtag_pointer(const void*,const void*);

// hash_string(texto, size):  funcao de dispersao de uma hashtag, que recebe uma string
//                            texto e um inteiro 'size' com o tamanho da hashtable;
int hash_string(void*, int);

// hash_hashtag(h_tag, size): funcao de dispersao de uma hashtag, que recebe um ponteiro
//                            para uma hashtag (h_tag) e um inteiro com o tamanho da
//							  hashtable (size);
int hash_hashtag(void*, int);

#endif