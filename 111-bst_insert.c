#include "binary_trees.h"

/**
 * bst_insert - insert new node in a bst
 * @tree: double pointer to the root of the tree
 * @value: integer to be inserted
 * Return: inserted node or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *curr;

	if (!tree || !(*tree))
	{
		new = (bst_t *)binary_tree_node(NULL, value);
		*tree = new;
		return (*tree);
	}
	new = (bst_t *)binary_tree_node(NULL, value);
	curr = *tree;
	while (1)
	{
		if (value == curr->n)
			break;
		if (value < curr->n)
		{
			if (!curr->left)
			{
				curr->left = new;
				new->parent = curr;
				return (new);
			}
			curr = curr->left;
		}
		if (value > curr->n)
		{
			if (!curr->right)
			{
				curr->right = new;
				new->parent = curr;
				return (new);
			}
			curr = curr->right;
		}
	}
	free(new);
	return (NULL);
}
