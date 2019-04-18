/* * * * * * * * * * * * * * * *
 *  IAED || PROJETO 2 		   *
 *  80832 Margarida Ferreira   *
 *	81805 Duarte David		   *
 * * * * * * * * * * * * * * * */

#ifndef __HASHTABLE__
#define __HASHTABLE__

// hashtable: guarda uma tabela de ponteiros para void, o tamanho da tabela,
//            e o numero de elementos guardados;
typedef struct 
{
	void** array;
	int size;
	int n_elems;
} hashtable;

// ht_init(n): inicializa uma hashtable com o tamanho n;
hashtable* ht_init(int);

// ht_insert(ht_pt_pt, item_pt, hash): insere na hashtable cuja posicao de memoria e passada por
//									   referencia (ht_pt_pt) o item, passado tambem por referencia
//									   (item_pt), de acordo com a funcao de dispersao (hash),
//         							   igualmente passada por referencia;
void ht_insert(hashtable**, void*, int (*hash)(void*, int));

// ht_search(ht_pt, item_pt, compare, hash): recebe como argumento um ponteiro para uma hashtable
//					(ht_pt), um ponteiro para um item (item_pt), uma funcao que compara ponteiros
//                  para itens (compare), uma funcao de dispersao de itens (hash). Retorna um
//					ponteiro para o elemento da hashtable que retorne 0 ao ser comparado com o
//                  item, ou NULL, caso este nao exista;
void* ht_search(hashtable*, void*, int (*compare)(void*, void*), int (*hash)(void*, int));

// ht_free(ht_pt, delete_item): libera a memoria usada pela hashtable cuja posicao de memoria e
//                              dada por ht_pt, e cujos elementos podem ser apagados com a funcao
//								delete_item;
void ht_free(hashtable*, void (*delete_item)(void*));

// expand(ht_pt_pt, hash): aumenta o tamanho da hashtable cuja posicao de memoria e passada por
//						   referencia (ht_pt_pt), re-dispersando os elementos com a funcao de
//						   dispersao passada (hash);
void expand(hashtable**, int (*hash)(void*, int));

// ht_to_array(ht_pt, item_pt_array): coloca os ponteiros para os itens na hashtable passada por
//                                    referencia (ht_pt) num array (item_pt_array);
void ht_to_array(hashtable*, void**);

#endif