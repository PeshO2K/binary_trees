#include "binary_trees.h"
/**
 * parent_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Description: This function takes a pointer to a node in a binary tree
 * and returns a pointer to its sibling node. If the node is NULL, or the
 * parent is NULL, or the node has no sibling, the function returns NULL.
 *
 * Return: pointer to the sibling, or NULL if no sibling or if node is NULL
 */
binary_tree_t *parent_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);

}
/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Description: This function takes a pointer to a node in a binary tree
 * and returns a pointer to its uncle node. If the node is NULL, or the
 * parent is NULL, or the node has no uncle, the function returns NULL.
 *
 * Return: pointer to the uncle node, or NULL if no uncle or if node is NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	return (parent_sibling(node->parent));
}
