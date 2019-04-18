/* * * * * * * * * * * * * * * *
 *  IAED || PROJETO 2 		   *
 *  80832 Margarida Ferreira   *
 *	81805 Duarte David		   *
 * * * * * * * * * * * * * * * */

#include <stdlib.h>
#include "hashtable.h"

// ht_init(n): inicializa uma hashtable com o tamanho n;
hashtable* ht_init(int size)
{
	hashtable* new_ht = (hashtable*)malloc(sizeof(hashtable));
	
	new_ht->size = size;
	new_ht->n_elems = 0;
	
	// O calloc coloca os ponteiros em new_ht->array a NULL;
	new_ht->array = (void**)calloc(size, sizeof(void*));

	return new_ht;
}

// ht_insert(ht_pt_pt, item_pt, hash): insere na hashtable cuja posicao de memoria e passada por
//									   referencia (ht_pt_pt) o item, passado tambem por referencia
//									   (item_pt), de acordo com a funcao de dispersao (hash),
//         							   igualmente passada por referencia;
void ht_insert(hashtable** ht_pt, void* item, int (*hash)(void*, int))
{
	hashtable *ht = *ht_pt;
	int i = hash(item, ht->size);
	
	// Insere de acordo com a procura linear;
	while(ht->array[i])
		i = (i+1) % ht->size;
	
	ht->array[i] = item;
	
	// Se a tabela ja estiver metade cheia, expande.
	if(++ht->n_elems >= ht->size / 2)
		expand(ht_pt, hash);
}

// ht_search(ht_pt, item_pt, compare, hash): recebe como argumento um ponteiro para uma hashtable
//					(ht_pt), um ponteiro para um item (item_pt), uma funcao que compara ponteiros
//                  para itens (compare), uma funcao de dispersao de itens (hash). Retorna um
//					ponteiro para o elemento da hashtable que retorne 0 ao ser comparado com o
//                  item, ou NULL, caso este nao exista;
void* ht_search(hashtable* ht, void* item, int (*compare)(void*, void*), int (*hash)(void*, int))
{
	int i = hash(item, ht->size);
	
	// Procura linear;
	while(ht->array[i])
		if(!compare(ht->array[i], item))
			return ht->array[i];
		else
			i = (i+1) % ht->size;
	return NULL;
}

// ht_free(ht_pt, delete_item): libera a memoria usada pela hashtable cuja posicao de memoria e
//                              dada por ht_pt, e cujos elementos podem ser apagados com a funcao
//								delete_item;
void ht_free(hashtable* ht, void (*delete_item)(void*))
{
	int i;
	
	// Apaga todos os itens na tabela de dispersao
	for(i=0; i < ht->size; i++)
		if(ht->array[i])
			delete_item(ht->array[i]);
		
	free(ht->array);
	free(ht);
}

// expand(ht_pt_pt, hash): aumenta o tamanho da hashtable cuja posicao de memoria e passada por
//						   referencia (ht_pt_pt), re-dispersando os elementos com a funcao de
//						   dispersao passada (hash);
void expand(hashtable** old_ht_pt, int (*hash)(void*, int))
{
	int i;
	
	hashtable* old_ht = *old_ht_pt;
	hashtable* new_ht = ht_init(2 * old_ht->size);
	
	// Insere todos os itens da tabela antiga na nova
	for (i=0; i < old_ht->size; i++)
		if(old_ht->array[i])
			ht_insert(&new_ht, old_ht->array[i], hash);
	
	// Apaga tudo na tabela antiga excepto os itens guardados
	free(old_ht->array);
	free(old_ht);
	
	*old_ht_pt = new_ht;
}

// ht_to_array(ht_pt, item_pt_array): coloca os ponteiros para os itens na hashtable passada por
//                                    referencia (ht_pt) num array (item_pt_array);
void ht_to_array(hashtable* ht, void** array)
{
	int i, j;
	for(i=0, j=0; i < ht->size; i++)
		if(ht->array[i])
			array[j++] = ht->array[i];
}
