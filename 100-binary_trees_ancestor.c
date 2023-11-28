#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, your function must return NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	const binary_tree_t *tmp_first = first, *tmp_second;

	if (first == NULL || second == NULL)
		return (NULL);

	while (tmp_first)
	{
		tmp_second = second;
		while (tmp_second)
		{
			if (tmp_first == tmp_second)
				return ((binary_tree_t *)tmp_first);
			tmp_second = tmp_second->parent;
		}
		tmp_first = tmp_first->parent;
	}
	return (NULL);
}
