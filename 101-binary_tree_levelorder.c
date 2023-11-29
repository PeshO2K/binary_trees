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
 * tree_height - measures the height of a binary tree
 * @tree: root of the tree
 * Return: height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	if (tree)
		return (height_plus(tree) - 1);
	return (0);
}
/**
 * traverse_level - helper function to apply func to each node
 * @level: Level to traverse
 * @tree: pointer to tree to traverse
 * @func: pointer to function to apply on each node
 * Description: At each specified level, traversal is donr recursively
 * until the depth is reached, once reached the func is applied. Next,
 * the other branch of the tree/subtree is traversed to the same depth.
 * Return: void
*/
void traverse_level(size_t level, const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 0)
		func(tree->n);
	else
	{
		traverse_level(level - 1, tree->left, func);
		traverse_level(level - 1, tree->right, func);
	}
}
/**
 * binary_tree_levelorder - traverses binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 *
 * If tree or func is NULL, do nothing.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (tree && func)
	{
		height = tree_height(tree);
		while (level <= height)
		{
			/*printf("___Level: %ld___\n", level);*/
			traverse_level(level, tree, func);
			level++;
		}
	}
}
