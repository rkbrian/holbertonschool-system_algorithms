#include "heap.h"
#include "huffman.h"

/**
 * huffman_extract_and_insert - function that extracts the two nodes of the
 *  priority queue and insert a new one
 * @priority_queue: a pointer to the priority queue to extract from
 * Return: 1 on success or 0 on failure
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	size_t ab, data_a, data_b;
	binary_tree_node_t *new_node = NULL;
	char data = -1;

	if (!priority_queue || priority_queue->size < 2)
		return (0);
	new_node = (binary_tree_node_t *)heap_extract(priority_queue);
	data_a = ((symbol_t *)new_node->data)->freq;
	free(new_node->data), free(new_node);
	new_node = (binary_tree_node_t *)heap_extract(priority_queue);
	data_b = ((symbol_t *)new_node->data)->freq;
	ab = data_a + data_b, ((symbol_t *)new_node->data)->data = data;
	((symbol_t *)new_node->data)->freq = ab;
	heap_insert(priority_queue, new_node);
	return (1);
}
