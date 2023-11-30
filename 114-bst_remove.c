#include "binary_trees.h"

/**
 * parent_side - connects child to grand parent for single child
 * @curr: pointer that is being deleted
 */
void parent_side(bst_t *curr)
{
	bst_t *only_child;

	/* Getting the only child */
	if (curr->left && !curr->right)
		only_child = curr->left;
	else
		only_child = curr->right;

	/* Doing the connections */
	if (curr->parent && curr->parent->right == curr)
	{
		curr->parent->right = only_child;
		only_child->parent = curr->parent;
	}
	if (curr->parent && curr->parent->left == curr)
	{
		curr->parent->left = only_child;
		only_child->parent = curr->parent;
	}

	if (curr->parent && curr->parent->right == curr)
		curr->parent->right = NULL;
	else if (curr->parent && curr->parent->left == curr)
		curr->parent->left = NULL;
}

/**
 * subtree_min - Finds the minimum value in a binary tree.
 * @tree: A pointer to the root of the binary tree.
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
 * bst_search - searches value in a bst
 * @tree: pointer to the root
 * @value: value to be searched
 * Return: the node containing that value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *curr = tree;

	if (tree)
	{
		while (curr)
		{
			if (value == curr->n)
				return ((bst_t *)curr);
			if (value < curr->n)
				curr = curr->left;
			if (value > curr->n)
				curr = curr->right;
		}
	}
	return (NULL);
}

/**
 * has_both_children - runs some parts of the code for when
 * the node to delete has both left and right children
 * @cr: double pointer to the current node
 * @rpl: double pointer to the replacement node
 * @rt: double pointer to the root node
 * Return: the updated pointer to the root
 */
bst_t *has_both_children(bst_t **cr, bst_t **rpl, bst_t **rt)
{
	bst_t *curr = *cr, *repl = *rpl, *root = *rt;

	if (repl->parent->right == repl)
		repl->parent->right = NULL;
	else
		repl->parent->left = NULL;
	repl->parent = curr->parent;
	repl->left = curr->left;
	repl->right = curr->right;
	curr->left->parent = repl;
	curr->right->parent = repl;

	if (curr == root)
		root = repl;
	else if (curr->parent->right == curr)
		curr->parent->right = repl;
	else
		curr->parent->left = repl;
	return (root);
}

/**
 * bst_remove - Removes a node from a BST
 * @root: pointer to the root node
 * @value: value at the node to be removed
 * Return: pointer to the new root or old root if it hasn't changed.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *curr = root, *repl = NULL;

	if (root)
	{
		while (curr)
		{
			if (value == curr->n)
			{
				if (!curr->left && !curr->right)
				{
					if (curr->parent && curr->parent->right == curr)
						curr->parent->right = NULL;
					else if (curr->parent && curr->parent->left == curr)
						curr->parent->left = NULL;
					free(curr);
					break;
				}
				if ((!curr->left && curr->right) ||
				 (curr->left && !curr->right))
				{
					parent_side(curr);
					free(curr);
					break;
				}
				if (curr->left && curr->right)
				{
					repl = bst_search(curr->right, subtree_min(curr->right));
					root = has_both_children(&curr, &repl, &root);
					free(curr);
					break;
				}
			}
			curr = (value < curr->n) ? curr->left
			: (value > curr->n) ? curr->right : curr;
		}
	}
	return (root);
}
