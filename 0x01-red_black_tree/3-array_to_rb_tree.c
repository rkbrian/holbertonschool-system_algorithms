#include "rb_trees.h"

/**
 * array_to_rb_tree - build an Red-Black Tree from an array
 * @array: array of integers
 * @size: size of Red-Black Tree
 * Return: new Red-Black Tree root
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	rb_tree_t *rb_root = NULL;
	int i, num;

	if (!array || size <= 0)
		return (NULL);
	num = size;
	for (i = 0; (i < num) && (array[i] != '\0'); i++)
	{
		rb_tree_insert(&rb_root, array[i]);
	}
	return (rb_root);
}
