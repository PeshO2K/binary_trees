#include "binary_trees.h"

/**
 * binary_tree_size - returns the number of nodes in a tree
 * @tree: pointer to the root of the tree
 * Return: the size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
