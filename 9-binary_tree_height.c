#include "binary_trees.h"

/**
 * height_plus - helper function that returns the height + 1
 * @tree: root of the tree
 * Return: height of the tree + 1
 */
size_t height_plus(const binary_tree_t *tree)
{
	size_t left_n;
	size_t right_n;

	if (tree)
	{
		left_n = height_plus(tree->left);
		right_n = height_plus(tree->right);

		if (left_n > right_n)
			return (left_n + 1);
		return (right_n + 1);
	}

	return (0);
}


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: root of the tree
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
		return (height_plus(tree) - 1);
	return 0;
}
