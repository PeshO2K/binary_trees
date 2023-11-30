#include "binary_trees.h"

/**
 * array_to_bst - builds a BST from an array
 * @array: pointer to first element of the array
 * @size: number of elements in the array
 * Return: Pointer to the root node or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root, *init = NULL;
	size_t i = 1;

	if (size > 0)
	{
		root = bst_insert(&init, array[0]);
		if (!root)
			return (NULL);
		while (i < size)
		{
			bst_insert(&root, array[i]);
			i++;
		}
		return (root);
	}
	return (NULL);
}
