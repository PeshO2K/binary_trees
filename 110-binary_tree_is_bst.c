#include "binary_trees.h"

/**
 * subtree_max - Finds the maximum value in a binary tree.
 *
 * @tree: A pointer to the root of the binary tree.
 *
 * Return: The maximum value in the binary tree.
 */
int subtree_max(const binary_tree_t *tree)
{
	int left, right, max_value;

	if (!tree)
		return (INT_MIN);

	left = subtree_max(tree->left);
	right = subtree_max(tree->right);

	if (left >= right)
		max_value = left;
	else
		max_value = right;
	if (max_value < tree->n)
		max_value = tree->n;

	return (max_value);
}

/**
 * subtree_min - Finds the minimum value in a binary tree.
 *
 * @tree: A pointer to the root of the binary tree.
 *
 * Return: The minimum value in the binary tree.
 */
int subtree_min(const binary_tree_t *tree)
{
	int min_value, left, right;

	if (tree)
	{
		left = subtree_min(tree->left);
		right = subtree_min(tree->right);

		min_value = (left < right) ? left : right;
		min_value = (tree->n < min_value) ? tree->n : min_value;

		return (min_value);
	}

	return (INT_MAX);
}

/**
 * is_bst_helper - helper func for checking bst
 * @tree: root node
 * Return: 1 if is bst, 0 otherwise, 1 if NULL root
 */
int is_bst_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (tree->left && subtree_max(tree->left) >= tree->n)
		return (0);
	if (tree->right && subtree_min(tree->right) <= tree->n)
		return (0);
	if (!is_bst_helper(tree->left) || !is_bst_helper(tree->right))
		return (0);
	return (1);
}
/**
 * is_bst - helper func for checking bst
 * @tree: root node
 * @min: minimum limit
 * @max: maximum limit
 * Return: 1 if is bst, 0 otherwise, 1 if NULL root
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst(tree->left, min, tree->n) &&
	is_bst(tree->right, tree->n, max));

}
/**
 * binary_tree_is_bst - checks if a BT is a valid BST
 * @tree: pointer to the root node
 * Return: 1 if BST, 0 otherwise, 0 also for NULL root
 */
	int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst(tree, INT_MIN, INT_MAX));
}
