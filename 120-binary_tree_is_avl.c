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
		left_n = height_plus(tree->left) + 1;
		right_n = height_plus(tree->right) + 1;
		return ((left_n > right_n) ? left_n : right_n);
	}

	return (-1);
}

/**
 * is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root of the binary tree
 * @min: minimum limit
 * @max: maximum limit
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
	size_t left_h, right_h, diff;

	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);

	left_h = height_plus(tree->left);
	right_h = height_plus(tree->right);
	diff = (-left_h < -right_h) ? (left_h - right_h) : (right_h - left_h);
	return ((diff > 1) ? 0 : (is_avl(tree->left, min, tree->n) &&
	is_avl(tree->right, tree->n, max)));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root of the binary tree
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	return ((tree) ? is_avl(tree, INT_MIN, INT_MAX) : 0);
}
