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

int tree_init(tree*);
size_t tree_height(tree*);
int tree_insert(tree*, const void*);
node* tree_search(tree*, const void*);
void tree_remove(tree*, const void*);
void tree_destory(tree*);


#endif // TREE_H
