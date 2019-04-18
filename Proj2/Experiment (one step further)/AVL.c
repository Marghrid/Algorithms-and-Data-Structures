/* * * * * * * * * * * * * * * *
 *  IAED || PROJETO 2 		   *
 *  80832 Margarida Ferreira   *
 *	81805 Duarte David		   *
 * * * * * * * * * * * * * * * */
 
#include <stdlib.h>
#include "AVL.h"

//REMOVER NO FIM!
#include <stdio.h>

avl_link new_avl_node(void* item)
{
	avl_link x = (avl_link)malloc(sizeof(struct avl_node));
	x->item = item;
	x->l = NULL;
	x->r = NULL;
	x->height = 1;
	return x;
}

int avl_height(avl_link h)
{
	if (!h) 
		return 0;
	return h->height;
} 

void avl_rotL(avl_link* h)
{
	int height_left, height_right;

	avl_link tmp = *h;
	*h = tmp->r;
	tmp->r = (*h)->l;
	(*h)->l = tmp;

	height_left = avl_height(tmp->l);
	height_right = avl_height(tmp->r);

 	tmp->height = height_left > height_right ? height_left + 1 : height_right + 1;

 	height_left = avl_height((*h)->l);
 	height_right = avl_height((*h)->r);

 	(*h)->height = height_left > height_right ? height_left + 1 : height_right + 1;
}

void avl_rotR(avl_link* h)
{
	int height_left, height_right;

	avl_link tmp = *h;
	*h = tmp->l;
	tmp->l = (*h)->r;
	(*h)->r = tmp;

	height_left = avl_height(tmp->l);
	height_right = avl_height(tmp->r);

 	tmp->height = height_left > height_right ? height_left + 1 : height_right + 1;

 	height_left = avl_height((*h)->l);
 	height_right = avl_height((*h)->r);

 	(*h)->height = height_left > height_right ? height_left + 1 : height_right + 1;
}

void avl_rotLR(avl_link* h)
{
 	if (!(*h))
 		return;
	avl_rotL(&((*h)->l));
 	avl_rotR(h);
}

void avl_rotRL(avl_link* h)
{
 	if (!(*h))
 		return;
 	avl_rotR(&((*h)->r));
 	avl_rotL(h);
}

int avl_get_balance_factor(avl_link h)
{
	if(!h)
 		return 0;
	return avl_height(h->l) - avl_height(h->r);
} 

void balance_avl(avl_link* h)
{
	int balance_factor;
	if (*h == NULL)
		return;
	balance_factor = avl_get_balance_factor(*h);
	if (balance_factor>1)
		if(avl_get_balance_factor((*h)->l)>=0)
			avl_rotR(h);
		else
			avl_rotLR(h);
	
	else if (balance_factor<-1)
		if (avl_get_balance_factor((*h)->r)<=0)
			avl_rotL(h);
		else
			avl_rotRL(h);
		
	else
	{
		int height_left = avl_height((*h)->l);
		int height_right = avl_height((*h)->r);
		(*h)->height = height_left > height_right ? 
			height_left + 1 : 
			height_right + 1;
	}
}

/*int avl_count(avl_link h)
{
	if (!h)
		return 0;
	
	return 1 + avl_count(h->l) + avl_count(h->r);
}*/

/*void* avl_search_whole(avl_link h, void* item, int(*compare)(void*, void*))
{
	short cmp;
	void* search_l;

	if(!h)
		return NULL;

	cmp = compare(item, h->item);
	if(!cmp)
		return h->item;

	search_l = avl_search_whole(h->l, item, compare);

	if(search_l)
		return search_l;
	else
		return	avl_search_whole(h->r, item, compare);
}*/

void* avl_search(avl_link h, void* item, int (*compare)(void*, void*))
{
		if(!h)
			return NULL;
		short int cmp = compare(h->item, item);
		//Nota: Estamos a assumir que compare retorna -1 se o primeiro argumento for menor.
		if(!cmp)
			return h->item;
		if(cmp<0)
			return avl_search(h->r, item, compare);
		else
			return avl_search(h->l, item, compare);
}

void avl_insert(avl_link* h, void* item, int (*compare)(void*, void*))
{
	if(!(*h))
	{
		*h = new_avl_node(item);
		return;
	}
	if(compare(item, (*h)->item) < 0)
		avl_insert(&((*h)->l), item, compare);
	else
		avl_insert(&((*h)->r), item, compare);
}

void avl_sort(avl_link h, void (*print)(void*))
{
	if (!h)
		return;
	avl_sort(h->l, print);
	print(h->item);
	avl_sort(h->r, print);
}

void avl_free(avl_link h, void (*delete_item)(void*))
{
	if (!h)
		return;
	avl_free(h->l, delete_item);
	avl_free(h->r, delete_item);
	delete_item(h->item);
	free(h);
}

void avl_delete(avl_link* h, void* item,
				int (*compare)(void*, void*), 
				void (*delete_item)(void*))
{
	short cmp;
	if ((*h))
	{
		cmp = compare(item, (*h)->item);
		if(cmp == -1)
			avl_delete(&((*h)->l), item, compare, delete_item);
		else if(cmp == 1)
			avl_delete(&((*h)->r), item, compare, delete_item);
		else if((*h)->l && (*h)->r)
		{
			avl_link aux = avl_max((*h)->l);
			{
				void* x;
				x=(*h)->item;
				(*h)->item = aux->item;
				aux->item = x;
			}
			avl_delete(&((*h)->l), aux->item, compare, delete_item);
		}
		else 
		{
			avl_link aux= (*h);
			if(!((*h)->l) && !((*h)->r))
				(*h)=NULL;
			else if (!((*h)->l))
				(*h)=(*h)->r;
			else
				(*h)=(*h)->l;
			delete_item(aux->item);
			free(aux);
		}
	balance_avl(h);
	}
}

avl_link avl_max(avl_link h)
{
	if(!h || !(h->r))
		return h;
	return avl_max(h->r);
}

/*
avl_link avl_min(avl_link h)
{
	if(!h || !(h->l))
		return h;
	return avl_min(h->l);
}
*/
//void avl_delete(avl_link* h, void*, void (*delete)(void*))
