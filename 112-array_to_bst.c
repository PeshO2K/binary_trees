#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root node
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}

/**
 * array_to_bst - builds a BST from an array
 * @array: pointer to first element of the array
 * @size: number of elements in the array
 * Return: Pointer to the root node or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root, *tmp, *init = NULL;
	size_t i = 1;

	if (size > 0)
	{
		root = bst_insert(&init, array[0]);
		if (!root)
			return (NULL);
		while (i < size)
		{
			tmp = bst_insert(&root, array[i]);
			if (!tmp)
			{
				binary_tree_delete((binary_tree_t *)root);
				return (NULL);
			}
			i++;
		}
		return (root);
	}
	return (NULL);
}
