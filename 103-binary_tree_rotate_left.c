#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: A pointer to the new root after the left-rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree && tree->right)
	{
		new_root = tree->right;
		tree->right = new_root->left;

		if (new_root->left)
		{
			new_root->left->parent = tree;
		}
		new_root->parent = tree->parent;
		if (!tree->parent)
		{
			new_root->parent = NULL;
		}
		else if (tree->parent->left == tree)
		{
			tree->parent->left = new_root;
		}
		else
		{
			tree->parent->right = new_root;
		}

		new_root->left = tree;
		tree->parent = new_root;
		return (new_root);

	}
	return (NULL);
}
