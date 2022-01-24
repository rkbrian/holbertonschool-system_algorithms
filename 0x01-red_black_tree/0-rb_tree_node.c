#include "rb_trees.h"

/**
 * rb_tree_node - create a red black tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * @color: color of the new node, red or black
 * Return: a pointer to the new node, or NULL on failure
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *newnode = NULL;

	newnode = malloc(sizeof(rb_tree_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL, newnode->right = NULL;
	newnode->color = color;
	return (newnode);
}
