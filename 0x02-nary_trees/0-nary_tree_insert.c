#include "nary_trees.h"

/**
 * nary_tree_insert - function that inserts a node in a N-ary tree.
 * @parent: a pointer to the parent node.
 * @str: the string to be stored in the created node. It must be duplicated.
 * Return: a pointer to the created node, or NULL on failure.
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *node, *curr_child = NULL;
	char *new_str = NULL;

	if (!str)
		return (NULL);
	node = malloc(sizeof(nary_tree_t));
	if (!node)
		return (NULL);
	new_str = strdup(str);
	if (!new_str)
	{
		free(node);
		return (NULL);
	}
	node->children = NULL, node->nb_children = 0;
	node->next = NULL, node->content = new_str, node->parent = parent;
	if (parent)
	{
		curr_child = parent->children, parent->children = node;
		node->next = curr_child, parent->nb_children++;
	}
	return (node);
}
