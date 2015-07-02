#ifndef TREE_H
#define TREE_H

#include <stddef.h> // size_t

typedef struct _node {
	struct _node* left;
	struct _node* right;
	void* data;
	//compare cp;
} node;

typedef node tree;

typedef int (*compare)(void*, void*);

extern size_t tree_height(tree** const);
extern int tree_insert(tree**, const void*, compare);
extern void tree_inorder(tree** const, list* lst);
extern void tree_preorder(tree** const, list* lst);
extern void tree_postorder(tree** const, list* lst);
extern int tree_search(tree** const, const void* value);
extern void tree_remove(tree**, const void*);
extern void tree_destory(tree**);


#endif // TREE_H
