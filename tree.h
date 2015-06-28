#ifndef TREE_H
#define TREE_H

#include <stddef.h> // size_t

typedef struct _node {
	struct _node* left;
	struct _node* right;
	void* data;
} node;

typedef node tree;

extern size_t tree_height(tree** const);
extern int tree_insert(tree**, const void*);
extern void tree_inorder(tree** const);
extern void tree_preorder(tree** const);
extern void tree_postorder(tree** const);
extern node* tree_search(tree** const, const void*);
extern void tree_remove(tree**, const void*);
extern void tree_destory(tree**);


#endif // TREE_H
