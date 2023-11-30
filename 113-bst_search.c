#include "binary_trees.h"

/**
 * bst_search - searches value in a bst
 * @tree: pointer to the root
 * @value: value to be searched
 * Return: the node containing that value
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *curr = tree;

	if (tree)
	{
		while (curr)
		{
			if (value == curr->n)
				return ((bst_t *)curr);
			if (value < curr->n)
				curr = curr->left;
			if (value > curr->n)
				curr = curr->right;
		}
	}
	return (NULL);
}
