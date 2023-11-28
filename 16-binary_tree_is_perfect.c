#include "binary_trees.h"
#include <stdio.h>

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
	return (height_plus(tree) - 1);
}

/**
 * binary_tree_balance - calculates the balance of a tree
 * @tree: root node
 * Return: the balance
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h, right_h, ret = 0;

	if (tree)
	{
		left_h = binary_tree_height(tree->left);
		right_h = binary_tree_height(tree->right);
		ret = left_h - right_h;
	}
	return (ret);
}


/**
 * binary_tree_is_perfect - checks if a tree is perfect
 * @tree: root of the tree
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	/*if (binary_tree_balance(tree) == 0)
		return (1);
	else
		return (0);
	return (binary_tree_is_perfect(tree->left) *
			binary_tree_is_perfect(tree->right) *
			((tree->left && tree->right)));
	*/
	if (binary_tree_balance(tree) != 0)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (!tree->left || !tree->right)
		return (0);
	return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
}
