#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _node {
	struct _node* left;
	struct _node* right;
	void* data;
} node;

typedef struct _tree {
	struct _node* root;
	// other data here
} tree;

extern int tree_init(tree*);
extern size_t tree_height(tree*);
extern int tree_insert(tree*, const void*);
extern node* tree_search(tree*, const void*);
extern void tree_remove(tree*, const void*);
extern void tree_destory(tree*);


#endif // TREE_H
