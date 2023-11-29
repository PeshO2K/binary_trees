#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 128);
	root->left->right = binary_tree_node(root->left, 2);
	root->right->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 10);

	root->right->left = binary_tree_node(root->right, 4);

	binary_tree_print(root);
	printf("MIN[%d]\n", subtree_min(root));
	printf("MAX[%d]\n", subtree_max(root));

	return (0);
}
