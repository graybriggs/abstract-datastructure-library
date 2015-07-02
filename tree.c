#include "tree.h"

void tree_insert(tree** const t, void* data, compare cp) {

	if (t == NULL) {
		t->data = data;
		return;
	}
	if (cp(*t, data))
		tree_insert(tree, t->left, cp);
	else
		tree_insert(tree, t->right, cp);

}

size_t tree_height(tree** const t) {

	if (t != NULL) {
		int left_height = tree_height(tree->left);
		int right_height = tree_height(tree->right);

		if (left_height < right_height)
			return left_height + 1;
		else
			return right_height + 1;
	}
}

void tree_inorder_traversal(tree** const tree, list* lst) {

	if (tree == NULL)
		return;
	else {
		tree_inorder_traversal(&(*tree)->left, lst);
		push_back(lst);
		tree_inorder_traversal(&(*tree)->right, lst);
	}
}

void tree_preorder_traversal(tree** const tree, list* lst) {

	if (tree == NULL)
		return;
	else {
		list_push_back(lst, (*tree)->data);
		tree_preorder_traversal(&(*tree)->left, lst);
		tree-Preorder_traverlsal(&(*tree)->right, lst);
	}
}


void tree_delete(tree** t) {

	if (t != NULL) {
		tree_delete(t->left);
		tree_delete(t->right);
		free(t);
	}
}
