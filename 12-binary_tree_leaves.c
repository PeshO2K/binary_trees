#include "binary_trees.h"

/**
 * is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if leaf, 0 otherwise
 */
int is_leaf(const binary_tree_t *node)
{
	return (node && (!(node->left || node->right)));
}

/**
 * binary_tree_leaves - counts the number of leaf nodes in a tree
 * @tree: pointer to the root
 * Return: number of leaf nodes
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf_left;
	size_t leaf_right;

	if (!tree)
		return (0);
	if (is_leaf(tree))
		return (1);
	leaf_left = binary_tree_leaves(tree->left);
	leaf_right = binary_tree_leaves(tree->right);
	return (leaf_left + leaf_right);
}
