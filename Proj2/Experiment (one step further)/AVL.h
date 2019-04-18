/* * * * * * * * * * * * * * * *
 *  IAED || PROJETO 2 		   *
 *  80832 Margarida Ferreira   *
 *	81805 Duarte David		   *
 * * * * * * * * * * * * * * * */

 
#ifndef __AVL__
#define __AVL__

typedef struct avl_node *avl_link;

struct avl_node
{
	void *item;
	avl_link l, r;
	int height;
};

avl_link new_avl_node(void*);
void avl_init(avl_link*);
int avl_height(avl_link);
void avl_rotL(avl_link*);
void avl_rotR(avl_link*);
void avl_rotLR(avl_link*);
void avl_rotRL(avl_link*);
int avl_get_balance_factor(avl_link h);
void balance_avl(avl_link*);
//int avl_count(avl_link);
//void* avl_search_whole(avl_link, void*, int(*compare)(void*, void*));
void *avl_search(avl_link, void*, int (*compare)(void*, void*));
void avl_insert(avl_link*, void*, int (*compare)(void*, void*));
void avl_sort(avl_link, void (*print)(void*));
void avl_free(avl_link, void (*delete_item)(void*));
void avl_delete(avl_link*,void*, int(*compare)(void*, void*) ,void (*delete)(void*));
avl_link avl_max(avl_link);
//avl_link avl_min(avl_link);

#endif 