#include "heap.h"

/**
 * binary_tree_node - function that creates a generic Binary Tree node
 * @parent: a pointer to the parent node of the node to be created
 * @data: the data to be stored in the node
 * Return: a pointer to the created node, or NULL if it fails
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *new_node;

	if (!data)
		return (NULL);
	if (!parent)
	{
		parent = malloc(sizeof(binary_tree_node_t));
		if (!parent)
			return (NULL);
		parent->left = NULL, parent->right = NULL;
		parent->parent = NULL, parent->data = data;
		return (parent);
	}
	new_node = malloc(sizeof(binary_tree_node_t));
	if (!new_node)
		return (NULL);
	new_node->left = NULL, new_node->right = NULL;
	new_node->parent = parent, new_node->data = data;
	return (new_node);
}
