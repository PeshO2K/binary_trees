#include "binary_trees.h"

/**
 * binary_tree_depth - returns the depth of a node
 * @tree: node of the element for which we want to find the depth
 * Return: the depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || tree->parent == NULL)
		return (0);
	return (binary_tree_depth(tree->parent) + 1);
}
