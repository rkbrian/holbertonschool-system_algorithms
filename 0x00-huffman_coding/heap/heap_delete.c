#include "heap.h"

/**
 * heap_delete - function that deallocates a heap
 * @heap: a pointer to the heap to delete
 * @free_data: a pointer to a function that will be used to
 *  free the content of a node
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;
	if (heap->root)
		chain_free(heap->root, free_data);
	free(heap);
}

/**
 * chain_free - free all node recursively from given root/parent node
 * @node: the given root/parent node
 * @free_data: a pointer to a function that will be used to
 *  free the content of a node
 */
void chain_free(binary_tree_node_t *node, void (*free_data)(void *))
{
	binary_tree_node_t *left_node = NULL, *right_node = NULL;

	if (node)
	{
		left_node = node->left, right_node = node->right;
		if (free_data)
			free_data(node->data);
		free(node);
		chain_free(left_node, free_data);
		chain_free(right_node, free_data);
	}
}
